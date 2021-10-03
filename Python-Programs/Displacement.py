print("To Find Displacement Write:-\n 1st.InitialVelocity\n 2nd. Time Taken\n 3rd.Accelration")
u=int(input("Enter The Initial Velocity of Body(in Meters per Second):"))
t=int(input("Enter The Time Taken by Body(in Seconds):"))
a=int(input("Enter The Acceleration of Body(in Meters per Second Square):"))
s=u*t+1/2*a*t**2
print("This",s,"is The Displacement in Your case(in Meters)")
