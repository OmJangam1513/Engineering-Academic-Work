class RingElection:
    def __init__(self, processes):
        self.processes = sorted(processes)   # Maintain ring order
        self.coordinator = None

    def start_election(self, initiator):
        print("Election started by process", initiator)
        message = []
        n = len(self.processes)
        index = self.processes.index(initiator)

        # ----- Election Message Circulation -----
        for i in range(n):
            current = self.processes[(index + i) % n]
            next_process = self.processes[(index + i + 1) % n]
            print("Process", current, "passes Election message to", next_process)
            message.append(current)

        # Highest process ID becomes coordinator
        self.coordinator = max(message)
        print("\nProcess", self.coordinator, "has become the new coordinator.\n")

        # ----- Coordinator Announcement Circulation -----
        print("---- Coordinator Announcement Phase ----")
        coord_index = self.processes.index(self.coordinator)

        for i in range(n):
            current = self.processes[(coord_index + i) % n]
            next_process = self.processes[(coord_index + i + 1) % n]
            print("Process", self.coordinator, "is Coordinator → Message to PID", next_process)

    def show_coordinator(self):
        print("\nCurrent coordinator is:", self.coordinator)


# --- Main Program ---
n = int(input("Enter total number of processes: "))
processes = []

for i in range(n):
    p = int(input("Enter process id: "))
    processes.append(p)

initiator = int(input("Enter initiator id: "))

ring = RingElection(processes)
ring.start_election(initiator)
ring.show_coordinator()
