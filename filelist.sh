#!/bin/bash

function batch_convert() {
    for file in `ls $1`
    do
        if [ -d $1"/"$file ]
        then
            batch_convert $1"/"$file
        else
            ls  $1"/"$file
            #echo $1"/"$file
        fi
    done
}

batch_convert $1 
