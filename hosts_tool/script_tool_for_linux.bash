#!/usr/bin/env bash
# Pls check if 'custom' file is with this script before run.
if [ `whoami` = 'root' ]; then
    script_path=`dirname $0`
    cp /etc/hosts $script_path/hosts-`date +%F-%H%M%S`.bak
    wget https://raw.githubusercontent.com/racaljk/hosts/master/hosts -O $script_path/fetchedhosts
    cat $script_path/custom > /etc/hosts
    echo >> /etc/hosts
    cat $script_path/fetchedhosts >> /etc/hosts
else
    echo Sudo to run this script.
fi
