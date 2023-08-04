#!/bin/bash
ifconfig | grep ether | cut -b 15-31
