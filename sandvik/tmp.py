n, m = map(int, input().split())

s = []
t = []

for _ in range(n):
    s_i, t_i = map(int, input().split())
    s.append(s_i)
    t.append(t_i)

flying_to = [[] for _ in range(n)]

for i in range(m):
    s_i, d_i = map(int, input().split())
    flying_to[d_i].append(s_i)

countries = n
days = n

max_probabilities = [[0] * days for i in range(countries)]

# fill the table
max_probabilities[0][0] = 1.0

for day in range(1,days):  # fangen bei tag 2 an
    for country in range(countries):
        # do stuff
        border_open_probability = 1 - (day - s[country]) / (t[country] - s[country])
        pred_max_probabilities = [max_probabilities[day - 1][i]*(1 - (day - s[i]) / (t[i] - s[i])) for i in flying_to[country]] 
        pred_max_probabilities.append(0) # fallback
        max_probabilities[day][country] = max(pred_max_probabilities) * border_open_probability

# print(max_probabilites[2])
# print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in max_probabilities]))

print(max([max_probabilities[i][countries-1] for i in range(countries)]))
