    for a in A
        idx = searchsortedfirst(A, a+X)
        if idx > N
            continue
        end
        b = A[idx]
       if b - a == X
            return true
        end
    end
    return false
end

N, X = parse.(Int64, split(readline()))
A = parse.(Int64, split(readline()))
sort!(A)

if solve(A, N, X)
    println("Yes")
        
else
    println("No")
end

