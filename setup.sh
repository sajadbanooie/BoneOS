#Install Dependencies

echo "SETTING UP DEPENDENCIES"
if [ "$(uname)" == "Darwin" ]; then
  echo "RUNNING UNDER Max OSX"
   brew install nasm
   brew install gcc
   brew install gcc-multilib
   brew install qemu
   brew install grub-common
   brew install xorriso
   brew install grub-pc-bin   
   brew install supervisor
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
   echo pwd
   echo "RUNNING UNDER a linux distro"
    sudo apt-get update
	if [ -z "$TRAVIS" ]; then
		sudo apt-get install -y nasm gcc-5 gcc-5-multilib qemu grub-common xorriso grub-pc-bin supervisor
	else
		sudo apt-get install nasm gcc-5 gcc-5-multilib qemu grub-common xorriso grub-pc-bin supervisor
	fi
elif [ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]; then
    # Do something under Windows NT platform
    echo "BoneOS Isnt Available on Windows Operating Systems Yet."
    echo "You Can Code here : https://ide.c9.io/amanuel2/osdev , or contact us at : https://meta.boneos.org"
fi


