#ifndef RTCsec_h

#define RTCsec_h

 

// library interface description

class RealTimeClockSec

{

    // user-accessible "public" interface

public:

    RealTimeClockSec(void);

    void Set_Time(char hr, char mins, char secs);

    char RTC_sec; // This how you read the time, by reading the vars

    char RTC_min;

    char RTC_hr;

    void Inc_sec(void); // This methode should be invoked by an Interrupt call (see top of the file comment)

    // A few private methods

private:

    void Inc_min(void);

    void Inc_hr(void);

};

 

#endif