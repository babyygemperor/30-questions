#!/usr/bin/env python


class Student:

    def __init__(self):
        self.name = "No Name"
        self.rollNo = 0

    def get_data(self):
        self.name = input("Enter name : ")
        self.rollNo = input("Enter Roll Number : ")

    def print_data(self):
        print("------------------------------------------")
        print ("Name : ", self.name)
        print ("Roll Number : ", self.rollNo)


class Marks(Student):

    def __init__(self):
        Student.__init__(self)
        self.maths = 0
        self.chem = 0
        self.eng = 0
        self.phy = 0
        self.cs = 0

    def input_data(self):
        Student.get_data(self)
        self.maths = input("Enter Mathematics marks : ")
        self.chem = input("Enter Chemistry marks : ")
        self.eng = input("Enter English marks : ")
        self.phy = input("Enter Physics marks : ")
        self.cs = input("Enter Computer Science marks : ")

    def out_data(self):
        Student.print_data(self)
        print("Marks in Mathematics : ", self.maths)
        print("Marks in Chemistry : ", self.chem)
        print("Marks in English : ", self.eng)
        print("Marks in Physics : ", self.phy)
        print("Marks in Computer Science : ", self.cs)


def main():
    marks = Marks()
    marks.input_data()
    marks.out_data()


main()
