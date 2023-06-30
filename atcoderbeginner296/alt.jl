function solve(s)    
    for i = 2:length(s)
        if s[i-1] == s[i]
            return false
        end
    end
    return true
end

n = readline()
s = readline()

if solve(s)
    println("Yes")
else
    println("No")
end
