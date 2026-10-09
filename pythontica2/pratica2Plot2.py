import matplotlib.pyplot as plt

n_list = []
t1_list = []
t2_list = []

dataType = "n"

with open("dados.txt", "r", encoding="utf-8") as file:
    for line in file:
        if dataType == "n":
            n_list.append(int(line.strip()))
            dataType = "t1"
        elif dataType == "t1":
            t1_list.append(int(line.strip()))
            dataType = "t2"
        elif dataType == "t2":
            t2_list.append(int(line.strip()))
            dataType = "n"


plt.plot(n_list, t2_list, label="Algoritmo 2", color="blue")

plt.xlabel("n")
plt.ylabel("μs")
plt.title("Pratica 2")
plt.legend()
plt.show()


            
