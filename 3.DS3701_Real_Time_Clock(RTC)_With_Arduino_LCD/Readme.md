Design  a real time clock using DS1307 RTC with Arduino ANd Show the Time and Date on LCD

Steps/Procedure:-

1. Start I2C Serial Communication.

2. First Send the DS1307 Address as 20 HexaDecimal Default Value and Selecte Read Operation

3. Read the Year,Month,Date,HOURS,Minutes,Seconds one by one then send Ackowledment

4. Read the Year and Send No Acknowledment 

5. Stop I2C Communication.





--->What IS RTC...?

1. An RTC or Real Time Clock is a Timekeeping device, usually in the form of an Integrated Circuit (IC). An RTC is battery powered and keeps track of the current time even when there is no power.

2. Real Time Clock ICs are present in computers, servers, many embedded systems and in fact they are used wherever it is required to keep an accurate time. 

---> 2.What Is DS1307 Real Time Clock

1. The DS1307 RTC is a low cost, low power real time clock IC that can maintain full clock and calendar i.e. hours, minutes, seconds as well as year, month and day. Some of the well-known features of the popular DS1307 RTC are mentioned below.


2. DS1307 RTC is available as modules, which consists of all the necessary components like Battery, connectors, pull-up resistors and crystal. 


1.1. Complete Timekeeping functionality i.e. hours, minutes, seconds, year with leap-year, month, date of the month and day of the week.
1.2 Valid up to the year 2100.
1.3 Low power consumption: consumes less than 500nA while operated on battery.
1.4 Automatic switching to battery supply in case of power failure.
1.5. 24 – hour or 12- hour clock with AM/PM indicator. 


