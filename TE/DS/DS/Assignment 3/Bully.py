class BullyElection:
    def __init__(self, processes):
        self.processes = sorted(processes)
        self.coordinator = None

    def start_election(self, initiator):
        print("Election started by process", initiator)
        higher = []

        for p in self.processes:
            if p > initiator:
                higher.append(p)

        if len(higher) == 0:
            self.coordinator = initiator
            print("Process", initiator, "becomes the coordinator.")
        else:
            for p in higher:
                print("Process", initiator, "sends election message to", p)
                
            new_initiator = max(higher)
            print("Process", new_initiator, "takes over the election...")
            self.start_election(new_initiator)

    def show_coordinator(self):
        print("Current coordinator is:", self.coordinator)


# --- Main program ---
n = int(input("Enter total number of processes: "))
processes = []

for i in range(n):
    p = int(input("Enter process id: "))
    processes.append(p)

initiator = int(input("Enter initiator id: "))

bully = BullyElection(processes)
bully.start_election(initiator)
bully.show_coordinator()
