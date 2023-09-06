#PUSH_SWAP

define psaa
    set $array1 = $arg0
    set $array2 = $arg1
    set $index = 0
    set $len = $arg2
    printf "%-20s %-20s\n", "stack_a", "stack_b"
    printf "%-6s %-6s %-6s %-6s\n", "active", "index", "active", "index"
    while ($index < $len)
		if ($array1[$index].active == 0)
			set $index = $index + 1
			continue
		end
		if ($array1[$index].active == 1)
            printf "%-6d %-6d ", $array1[$index].active, $array1[$index].index
        else
            printf "%-6s %-6s ", " ", " "
        end
        if ($array2[$index].active == 1)
            printf "%-6d %-6d\n", $array2[$index].active, $array2[$index].index
        else
            printf "\n"
        end
        set $index = $index + 1
    end
end
document psaa
PUSH_SWAP
print 2 stack arrays next to each other for as long as at least one exists
end

define r20
	run 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
end
document r20
PUSH_SWAP
run with arguments from 20 to 1
end

define psa
	set $array = $arg0
	set $index = 0
	set $len = $arg1
	while $index < $len
		print $array[$index]
		set $index = $index + 1
	end
	printf "\n"
end
document psa
PUSH_SWAP
print entire stack array and all of its content
end


define plist
  set $node = $arg0
  while $node
    printf "%d ", $node->content
    set $node = $node->next
  end
  printf "\n"
end
document plist
print linked list and all following nodes
node must have *next and *content
end

define rm20
	break master
	run 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
end
document rm20
PUSH_SWAP
break at master and then r20
end
