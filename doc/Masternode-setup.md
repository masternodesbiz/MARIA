# Maria Core Masternode Setup Guide

A short guide on how to create a Masternode for Maria Coin.

## Local Wallet Setup

These first steps are for the wallet that will be holding your Maria Collateral. (100,000 MARIA)

![Screenshot 2022-12-01 at 9 08 16 AM](https://user-images.githubusercontent.com/45834289/205088890-18d14103-c27d-4f7d-b966-6de13394d125.png)

If you have atleast 100,000 MARIA coins, we can go to the MASTERNODES tab and from there select "Create Masternode Controller"

![Screenshot 2022-12-01 at 9 08 26 AM](https://user-images.githubusercontent.com/45834289/205088886-0e11d112-edd7-4b1d-a4f9-61fb9b471b3d.png)

The masternode controller will walk you through the steps to setup everything required on your local wallet.

![Screenshot 2022-12-01 at 9 08 36 AM](https://user-images.githubusercontent.com/45834289/205088885-a1f0bd85-9ee3-4e90-842e-19698ec26abc.png)

![Screenshot 2022-12-01 at 9 08 44 AM](https://user-images.githubusercontent.com/45834289/205088884-4825859f-21d3-4efd-ad1f-ac398c45874e.png)

This screen we will have to add our name for the masternode, which if you see my screenshots mine are "Masternode1" but you can call it anything you like, many will commonly do "mn1" "mn2" so on and so forth.

![Screenshot 2022-12-01 at 9 08 56 AM](https://user-images.githubusercontent.com/45834289/205088882-bb263f96-e8d3-410b-ae1f-c712b5851fa7.png)

This next screen is requesting the IP address for the VPS you have purchased in order to setup your masternode. A place that you can get one is from say, https://hostmaria.com. After clicking next, it will automatically send the coins to a new address and lock them to setup a masternode. The sent transaction requires atleast 15 confirmations before you can try starting the masternode, but that should be more than enough time to start configuring the VPS and it should all be ready by the time it is complete.

Upon completion we need to save some data we can get from our local wallet. If you are still in the masternode tab you need to click on the 3 dots next to your newly created masternode name. After clicking on it there is a tab called Info and it will have a copy button.

![Screenshot 2022-12-01 at 9 09 20 AM](https://user-images.githubusercontent.com/45834289/205088878-c4349601-12e8-4493-b048-12a4ab5588b3.png)

Now, we need to click on the copy button by "Export data to run the masternode on a remote server", this will copy to your clipboard information like the following:

```masternode=1
externalip=51.161.166.129
masternodeaddr=51.161.166.129:47773
masternodeprivkey=88wsw6D2KTQzSxEWD6WFYGtb9CcYqecGKA6UjTqkda313kr4VzD
```

We will save this information in a notepad somewhere for later after we start configuring our VPS.

## VPS Setup

This portion of the guide makes several assumptions:
- Already purchased a VPS
- Understanding of SSH
- Understanding of basic linux commands

For your VPS it is recommended to use minimally Ubuntu 18.04 for the Operating System.

Upon logging into your VPS with SSH, you will need to do several things

- Download the linux wallet
- Setup the maria.conf file
- Start the masternode
- Check the status

First things first lets update the system with the following commands
```
sudo apt-get update
sudo apt-get upgrade
```
This will take a few moments and upon completion we can simply run this command to download the wallet and extract it.
```
wget https://github.com/hostmaria/mariacoin/releases/download/1.8.1/maria-1.8.1-x86_64-linux-gnu.tar.gz && tar -xvf maria-1.8.1-x86_64-linux-gnu.tar.gz
```
Due to our coinhave the pre-requisites for Privacy Features like PIVX/ZCASH we need to make a directory for the sapling params so the wallet is able to run. Windows installer will do this automatically and same for the Mac .dmg.
Using these commands to set that up:
```
mkdir /root/.maria-params
cp /root/maria-1.8.1/share/maria/* /root/.maria-params
```
Next, we will configure our masternode we will start by making the default coin directory and configuration files below.
```
mkdir /root/.maria
nano /root/.maria/maria.conf
```
Here we will need to use that saved information from our local wallet and copy and paste it into the conf file.
You will also have to add the following
```
externalip=IP_HERE
rpcbind=127.0.0.1
bind=IP_HERE
rpcuser=supersecureusername
rpcpassword=supersecurepassword
rpcallowip=127.0.0.1
rpcport=47774
server=1
daemon=1
listen=1
port=47773
maxconnections=256
addnode=188.40.233.39
addnode=188.40.233.40
addnode=188.40.233.41
```
Theres a few modifications to the places, with IP_HERE we would replace with the IP address of the VPS that we are logged into. The RPC username/passwords need to be set for checking and talking to your masternode. RPC Port can be adjusted by Port can not.

Afterwards save and close the conf file.

Finally, we can start our masternode daemon on the server to sync!
```
./maria-1.8.1/bin/mariad 
```
This should initiate the daemon based on if you have been following the guide up until this point.

After waiting a few moments we can check the sync process by using
```
./maria-1.8.1/bin/maria-cli getblockcount
```
Once it matches the explorer https://explorer.mariacoin.com/ you can then go back to your local wallet on your normal PC and start the masternode.

Happy Masternoding!!






