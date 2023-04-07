# Creating a Seednode for Maria Core

## Preface

A seed node is one of the main IP's wallets/masternodes/peers connect to in order to get blockchain data. In attempts to become more decentralized this should be some community members to help promote more network connectivity and decentralization.

This guide assumes basic Linux knowledge/SSH knowledge as the guide is going through the setup on a Linux based VPS that is already purchased. You can actually setup a seed node on any computer running 24/7 and the main focus is the maria.conf file being modified appropriately.

## Seednode Setup

Login to your Linux VPS through SSH

First steps would be downloading and unzipping the wallet files.

```
wget https://github.com/hostmaria/mariacoin/releases/download/1.8.1/maria-1.8.1-x86_64-linux-gnu.tar.gz && tar -xvf maria-1.8.1-x86_64-linux-gnu.tar.gz
```

After unzipping we will make our .maria-params directory and setup the .maria directory and maria.conf

```
mkdir /root/.maria-params
mkdir /root/.maria
nano /root/.maria/maria.conf
```

The last line opens the text editor to modify the conf file, to which just copy and paste the following

```
daemon=1
server=1
listen=1
maxconnections=512
rpcuser=somesupersecureuser
rpcpassword=somesupersecurepassword
rpcport=47774
port=47773
bind=IPHERE
addnode=188.40.233.40
addnode=188.40.233.41
addnode=188.40.233.39
```

That is all! Now just run the daemon with the following command.

```
/root/maria-1.8.1/bin/mariad
```

The key portions of a seed node is allowing a lot of connections to the node and the best uptime possible to provide connectivity for users and services.
