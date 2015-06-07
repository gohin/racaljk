#!/bin/bash

dir="$( cd "$( dirname "$0" )" && pwd )"
cd $dir
rm hosts.bak
rm hosts
wget "https://raw.githubusercontent.com/racaljk/hosts/master/hosts"
cp /etc/hosts ./hosts.bak
echo -e \n >> hosts
echo "127.0.0.1 "hostname >> hosts
cp ./hosts /etc/hosts
echo "Success"