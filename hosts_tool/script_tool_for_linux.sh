#!/usr/bin/env bash
if [ ${UID} != 0 ]; then
    cp /etc/hosts ./hosts-$(date +%F-%H%M%S).bak
    wget https://raw.githubusercontent.com/racaljk/hosts/master/hosts -O ./fetchedhosts

    echo ./fetchedhosts >> /etc/hosts
    echo Success.
else
    echo permission denied, are you root?
fi
