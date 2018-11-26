# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, pkgs, ... }:

let
  cloudInitConfig =
    ''
       system_info:
         distro: nixos
         default_user:
           name: nixos
       users:
         - default
       disable_root: true
       preserve_hostname: false
       cloud_init_modules:
         - migrator
         - seed_random
         - bootcmd
         - write-files
         - growpart
         - resizefs
         - update_etc_hosts
         - ca-certs
         - rsyslog
         - users-groups
	 - ssh
       cloud_config_modules:
         - disk_setup
         - mounts
         - ssh-import-id
         - set-passwords
         - timezone
         - disable-ec2-metadata
         - runcmd
         - ssh-import-id
       cloud_final_modules:
         - rightscale_userdata
         - scripts-vendor
         - scripts-per-once
         - scripts-per-boot
         - scripts-per-instance
         - scripts-user
         - ssh-authkey-fingerprints
         - keys-to-console
         - phone-home
         - final-message
         - power-state-change
    '';
    nixosHashedPasswd = "$6$fx92Ndm.I$ikwE5nhSHTWy8k/FVGbAcv8YpHAbVgv9uMJXvUPjKXeSMgt3Uxr2iRInvrmZiWM0m6jCTJVmN5RNQAkDUPH0W.";
in {
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
    ];

  # Use the GRUB 2 boot loader.
  boot.loader.grub.enable = true;
  boot.loader.grub.version = 2;
  # Define on which hard drive you want to install Grub.
  boot.loader.grub.device = "/dev/vda";

  networking.networkmanager.enable = false;
  networking.hostName = "felix-lang.org";

  #
  # Disable firewall in Cloud images by default; should be
  # handled by cloud manager config instead.
  #
  networking.firewall.enable = false;

  # Select internationalisation properties.
  # i18n = {
  #   consoleFont = "Lat2-Terminus16";
  #   consoleKeyMap = "us";
  #   defaultLocale = "en_US.UTF-8";
  # };

  # Set your time zone.
  # time.timeZone = "Europe/Amsterdam";

  # List packages installed in system profile. To search by name, run:
  # $ nix-env -qaP | grep wget
  environment.systemPackages = with pkgs; [
    # General
    mkpasswd
    wget 
    # Editors
    emacs vim nano
    # Desktop
    icewm
    # Development
    git tmux
    # Cloud
    cloud-init
  ];

  # List services that you want to enable:

  # Enable the OpenSSH daemon.
  services.openssh.enable = true;
  services.openssh.permitRootLogin = "without-password";
  services.openssh.challengeResponseAuthentication = false;

  # Enable cloud-init
  # TODO: fix config file install: https://github.com/NixOS/nixpkgs/issues/50366
  services.cloud-init.enable = true;
  services.cloud-init.config = cloudInitConfig;

  # services.nfs.server.enable = false;

  # Enable CUPS to print documents.
  # services.printing.enable = true;

  # Enable the X11 windowing system.
  services.xserver.enable = true;
  services.xserver.layout = "us";
  # services.xserver.xkbOptions = "eurosign:e";

  services.xserver.windowManager.icewm.enable = true;
  # Enable the KDE Desktop Environment.
  # services.xserver.displayManager.kdm.enable = true;
  # services.xserver.desktopManager.kde4.enable = true;

  users.mutableUsers = false;
  users.users.nixos = {
    isNormalUser = true;
    extraGroups = [ "wheel" "networkmanager" ];
    home = "/home/nixos";
    description = "Default system user";
    hashedPassword = nixosHashedPasswd;
    openssh.authorizedKeys.keys = ["ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAACAQCvfDUTxx/eLkFRFZahGAqb7UPI32qSxf+SIEzIsa0ZQ3fGyQpGXwmWUXaJUyK30VedOZ6pnj9McBJ5g3qZm/eTRVcVgOP6KqG/YnChg5Qg7O3fROjeVY77LuYs6MCKavF+nE+CTgQ7IbRYlAMkdaMM6DElQ0huQIf/ekmP9yWvd25fuHoCHMDSB3kfzOU6C+fr0qIuQQkj/oq++pRMYbVgZ6RESWV83ULmorLrn/otH+/DInrVIclA+RsF188VfaJQQOCFNO0eVlBKgl+zFqdTB4XVu3TOTq7mAsAfv08qE5msyv8fZaZLLoL935ktiuogQCy8vgYrhLPb9/mILNqqnWuoozjNDdu7kwZcOg5OzsVhxuhOx70MJHZeBwkXI2O6194ioTWIn4GeI1OBabeaLl5Wp+TfPIL87QSXM9vk1IvAg44Mdux+teuBmdZXtzi4TgtKIs1fX3l3jMmSTmxzU7Mm72Nm2Aa11SVlYprqolOz+rrOiDCelnhhOmG55EbYLlm9nC3dnqULRj9pfrRBvUpWtV+jEyI7nhqx8XFvKf6jSq68JeY0QN1xKaekiNnN0Bo3VoNAtj9DBYfOTlCfs67VxL5+Cvn87wsOfQrdCmeU2TLCAL1UzhNaRHvHsqt30+8NeMe/O/sgwSHHWFbZp0Aq+yb4RBNpEFMB4UjSxw== beb82@cornell.edu"];
  };
  users.users.skaller = {
    isNormalUser = true;
    extraGroups = [ "wheel" "networkmanager" ];
    home = "/home/skaller";
    description = "Default system user";
    openssh.authorizedKeys.keys = ["ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAwuLRjPhrh5MA7iN1vbhcCVm9+GzqQGtW15WhDCLV0gcrW4vT/AudL2PigLSBSQBhWcrlD+Ju9eBI1PRKeKjW+KQvpsnsHgUYLHvFG1y4P6GlO6ig4Xht0mq3BmCH83yBosG/8qmWo/mwDwpipSG3YjnnkfMYjTo2JBs1rUKCjHXVULGG3kUKEdMpVz0E8J4JC2LMwh9DpBYhJDPpFzkdZrb/TTSbo+FlSBObyl9R8pj7xYFxcxMDZ+LBPbGJJCTW8uRN2JHkpS6SMUT6cfYUQXb+mYhy3sFaL/t8Sbch/CaOb0oyQaxyiXXnjaj6658sUnys3oF78HeMaBNjvhigVQ== johnskaller@110.20.10.221.optusnet.com.au"];
  };
  
  virtualisation.docker.enable = false; # currently not using docker

  containers.flx_web =
  { autoStart = true;
    config =
      { config, pkgs, ... }:
      { environment.systemPackages = with pkgs; [
	# Editors
	emacs vim nano
	# Development
	git
	# Other Felix deps
	gcc
	gmp
	ocaml-ng.ocamlPackages_4_06.ocaml
	python36Full
      ];
      users.mutableUsers = false;
      users.users.felix = {
        isNormalUser = true;
        home = "/home/felix";
        description = "A user for running the Felix web site";
	hashedPassword = "$6$D2PEwvRqQu/b$vmYgbWYmLr3WqvectZuw4CZ8S5moOweZK6aE8Kn23HujkkiTcGisHw/CT5emoBwYfMmh3K..gFQgrvF30wdrv1";
      };
      users.users.nixos = {
        isNormalUser = true;
        extraGroups = [ "wheel" "networkmanager" ];
        home = "/home/nixos";
        description = "Default system user";
	hashedPassword = nixosHashedPasswd;
      };
     
     # TODO: add command to test if git clone is needed, and git pull felix otherwise:
     # system.activationScripts = { text = ''
     #   sudo su felix -c ""
     #    
     # '';};
    };
  };
  
  # The NixOS release to be compatible with for stateful data such as databases.
  system.stateVersion = "16.03";

}
