#!/bin/bash

if [$# -ne 1]; then
	echo "Usage: ./push_automation num_of_task"
	exit 1
fi

git add .
git commit -m "feat_Task$1 implementation"
git push
