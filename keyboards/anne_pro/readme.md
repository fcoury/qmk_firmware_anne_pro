# Anne Pro

### Disclaimer: this is experimental and by doing so you may cause harm to you keyboard. Continue so by your own risk, We are not accountable for any damage os loss you may experience.

### Disclaimer 2: [Obins](http://obins.net), the designer and manufacturer of the Anne Pro keyboard, has no connection to this project, this is a standalone project started by a 3rd party individual and has no correlation with any enterprise or company of some sort.

Anne Pro is a 60% mechanical keyboard design and manufactured in China by [Obins](http://obins.net). It features a dual connection (Bluetooth and wired) and has limited programmability through the official obins apps.

So far what have I discovered:

1. Anne Pro runs on two STM32L151C8T6 chip (one for lighting control and another for firmware control, there is the Bluetooth flash but I'm ignoring it for now)
2. I've asked help on guitter.im and [skullydazed](https://github.com/skullydazed) pointed me to the clueboard 60 that runs on a similar chip (STM32F303). That's is probably the best starting point.
3. skullydazed also pointed that QMK depends on chibios to run ARM chips (like the STM32), so we need to check for STM32L151C8 (or STM32L1xx) in chibios files (so far I've found that they do have something, check [here](http://www.chibios.com/forum/viewtopic.php?t=1940)). Apparently they have support for the STM32L1xx family, which includes the board (hopefully) but this needs to be investigated further.
4. It's possible to install files to the keyboard by entering DFU mode (unplug keyboard USB + press ESC + press reset for 1 sec + release reset + release ESC + plug keyboard). In Mac OS I've installed [dfu-utils](http://dfu-util.sourceforge.net/) using homebrew (`homebrew install dfu-utils`) and was able to find the corresponding flash memories (command: `dfu-utils -l`) (keyboard controller, light controller and Bluetooth controller). This means that we can upload the file using dfu-utils once we are able to compile everything.

Preliminary next steps (more will come): 

1. change the clueboard source code in order to make it compatible with STM32L151C8 and Anne Pro specifics.
	* Remove unnecessary code from `anne_pro.h`
	* check if `matrix.c` files need modification
	* Check how `led.c` fits since it's in another controller
	* Find the correct parameters for file `mcuconf.h`
	* find the GPIO pin out for the specific controller
		* Need to complete the files in `boards/GENERIC_STM32_L151C8` based on clueboard `boards/GENERIC_STM_F303XC`
	* Change `keymaps/default/keymap.c` to conform to Anne Pro (if needed)
2. compile the modified code
3. upload to the Anne Pro
	* check dfu-utils (check the file format needed)
4. make sure it works
	* if works, have fun
	* otherwise, start from 1

	
## How to contribute

For now I thought of this workflow:

* fork this project
* clone your fork in your computer (`git clone <your_fork_url`)
* create a branch and start working (`git checkout -b name_of_your_branch`)
* commit your changes to your branch (`git commit`)
* publish your branch (`git push origin/branch_name`)
* rebase from master (`git rebase master`)(I thank you if you upload from upstream)
* force push after rebase (`git push -f`)
* merge your branch to master (can be done from github itself)
* create an Pull Request from your repo to this repo


### Ideas, code, knowledge or any other form of help is welcomed!

<!--* Maintainer: [josecostamartins](https://github.com/josecostamartins)-->
* Hardware Supported:
  * Anne Pro (under construction)
