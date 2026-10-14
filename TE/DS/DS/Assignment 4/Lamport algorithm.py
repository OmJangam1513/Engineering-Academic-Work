class process:

    def __init__(self,pid):
        self.pid=pid
        self.clock=0

    def local_event(self):
        self.clock+=1
        print(f"Process {self.pid} local event , clock= {self.clock}")

    def send_message(self,receiver):
        self.clock+=1
        print(f"process {self.pid} send message with timestamp {self.clock } to process {receiver.pid}")
        receiver.receive_message(self.clock,self.pid)

    def receive_message(self,timestamp , sender_pid):
        self.clock=max(self.clock,timestamp)+1
        print(f"Process {self.pid} received message from Process {sender_pid},updated clock : {self.clock}")


 

p1=process(1)
p2=process(2)

p1.local_event()
p1.send_message(p2)
p2.local_event()
p2.send_message(p1)
p1.local_event()
