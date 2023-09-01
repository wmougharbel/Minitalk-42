![](.extra/screen_minitalk.gif)

<h1>Minitalk</h1>
<h2>Overview</h2>

The Minitalk project is an exciting and hands-on project in the 42 curriculum designed to teach students about interprocess communication (IPC) using signals. In this project, students are tasked with creating a simple client-server communication system where one program (the client) sends a message to another program (the server) using signals. This project offers a practical introduction to low-level communication and signal handling.
Description
Interprocess Communication (IPC) with Signals

Minitalk explores the concept of IPC using signals, a fundamental mechanism in Unix-like operating systems. Students will create two programs: a client and a server. The client's objective is to send a string message to the server, which will receive and display the message. The catch is that the communication must occur exclusively through signals, specifically the SIGUSR1 and SIGUSR2 signals.
<h2>Project Objectives</h2>

    Implement a client program that sends messages as a series of binary signals (SIGUSR1 for '0' and SIGUSR2 for '1').
    Develop a server program that receives and interprets the binary signals to reconstruct the original message.
    Handle edge cases and ensure the correct order of signals for message reconstruction.

<h2>Key Concepts</h2>
Signals

	Minitalk is a hands-on opportunity to explore the concept of signals in Unix-based systems. Students will gain a practical understanding of how to send and receive signals between processes and utilize them for IPC.
	Binary Communication

	This project introduces binary communication, where characters are encoded as sequences of signals (0s and 1s). Students will learn how to encode and decode messages efficiently using signals.
	Error Handling

	Robust error handling is a crucial aspect of Minitalk. Students will need to implement error-checking mechanisms to ensure the reliability of signal transmission and message reconstruction.
<h2>Challenges</h2>

The Minitalk project presents several challenges to students:

    Designing a reliable and efficient signal-based communication protocol.
    Ensuring correct message reconstruction by handling signal ordering and potential signal loss.
    Implementing robust error handling and recovery mechanisms for signal transmission.

<h2>Learning Outcomes</h2>

By completing the Minitalk project, students will gain valuable knowledge and experience in the following areas:

    Interprocess communication (IPC) using signals.
    Signal handling and management in a Unix-like environment.
    Binary encoding and decoding for message transmission.
    Error detection and recovery strategies.
    Debugging and troubleshooting signal-based communication.
