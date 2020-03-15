#include<bits/stdc++.h>
using namespace std;

default_random_engine seed((unsigned)time(0));
double max_find(double a,double b)                                       //This utility function is used to find the maximum of two doubles.
{
    if(a>b)
        return a;
    else
        return b;
}


double poisson_distributed_random_variables(double mean)                //This Function is used to generate 
{                                                                       //poisson distributed random varibles.
    
    poisson_distribution<long unsigned int> random(mean);
    double temp=random(seed);
    //cout<<temp<<endl;
    return temp;  
}

double exponentially_distributed_random_variables(double mean)          //This function is used to generate 
{                                                                       //exponentially distributed random varibles.
        double temp,temp1;
        do{
            
            temp=((double)rand()/(RAND_MAX));
        }while(temp==0||temp==1);
        temp1=(-log(temp)*mean);
        //cout<<temp1<<endl;
        return temp1; 
}

void case_A(double arrival_rate,double service_rate,float hour)           //This function is used to implement the case A of the problem.
{
    
    arrival_rate=arrival_rate/3;                                        //arrival of passengers is getting divided into 3 queues
    if(service_rate<arrival_rate)                                      //Arrival rate must be greater than service rate to be in steady state
    {
        cout<<"Arrival rate must be greater than service rate to be in stable state\n ";
        return;
    }
    double n=hour;
    double inspected=0,arrival[3]={0};
    srand((unsigned)time(0));
    queue<pair<double,double>> q1,q2,q3;
    double finish_time[3]={0},wait_time[3]={0},ser_time[3]={0},no_waiting[3]={0};
    vector<double> map1,map2,map3;
    for(long int i=0;i<n;i++)                                                                               
    {
        //FOR QUEUE1
        double at=poisson_distributed_random_variables(3600/arrival_rate);          //poisson distributed arrival time 
        double st=exponentially_distributed_random_variables(3600/service_rate);    //exponentially distributed service time
        at=at+arrival[0];
        q1.push(make_pair(at,st));                                                  //putting passenger in queue1
        map1.push_back(at);
        arrival[0]=at;

        //FOR QUEUE2
        at=poisson_distributed_random_variables(3600/arrival_rate);                 //poisson distributed arrival time
        st=exponentially_distributed_random_variables(3600/service_rate);           //exponentially distributed service time
        at=at+arrival[1];
        q2.push(make_pair(at,st));                                                  //putting passenger in queue2
        map2.push_back(at);
        arrival[1]=at;

        //FOR QUEUE3
        at=poisson_distributed_random_variables(3600/arrival_rate);                 //poisson distributed arrival time
        st=exponentially_distributed_random_variables(3600/service_rate);           //exponentially distributed service time
        at=at+arrival[2];
        q3.push(make_pair(at,st));                                                  //putting passenger in queue3
        map3.push_back(at);
        arrival[2]=at;

    }

    cout<<"\nplease wait     ........\n";
    while(true)
    {
        if(q1.empty()&&q2.empty()&&q3.empty())          //if there's no passenger in any of the queues
            break;
        
        if(!q1.empty())                                 //if queue1 is not empty i.e. it has some passengers
        {
            pair<double,double> temp=q1.front();        //the passenger at the first position of queue1
            
            if(temp.first<finish_time[0])
                wait_time[0]+=finish_time[0]-temp.first;
         

            if(!q1.empty())                             //if queue1 is not empty i.e. it has some passengers       
            {
                if(q1.front().first<=finish_time[0])
                    inspected++;                        //passenger got inspected from queue
            }
            if(!q2.empty())                             //if queue2 is not empty i.e. it has some passengers
            {
                if(q2.front().first<=finish_time[1])
                    inspected++;                        //passenger got inspected from queue
            }
            if(!q3.empty())                             //if queue3 is not empty i.e. it has some passengers
            {
                if(q3.front().first<=finish_time[2])
                    inspected++;                        //passenger got inspected from queue
            }
            if(temp.first>=finish_time[0])
            {
                finish_time[0]=temp.first;
            }
            
            ser_time[0]+=temp.second;
            finish_time[0]+=temp.second;
            for(auto i=map1.begin();i!=map1.end()&&*i<=finish_time[0];i++)
            {
                    no_waiting[0]++;                        //no. of passengers waiting in queue1
            }
             map1.erase(map1.begin());  //see here
            q1.pop();
             
        }

        if(!q2.empty())                                     //if queue2 is not empty i.e. it has some passengers
        {
            pair<double,double> temp=q2.front();
              
            if(temp.first<finish_time[1])
                    wait_time[1]+=finish_time[1]-temp.first;

            if(!q1.empty())                                //if queue1 is not empty i.e. it has some passengers
            {
                if(q1.front().first<=finish_time[0])
                    inspected++;                            //passenger got inspected from queue
            }
            if(!q2.empty())                                 //if queue2 is not empty i.e. it has some passengers
            {
                if(q2.front().first<=finish_time[1])
                    inspected++;                            //passenger got inspected from queue
            }
            if(!q3.empty())                                 //if queue3 is not empty i.e. it has some passengers
            {
                if(q3.front().first<=finish_time[2])
                    inspected++;                            //passenger got inspected from queue
            }
            
           
            if(temp.first>=finish_time[1])
            {
                finish_time[1]=temp.first;
            }
            
            ser_time[1]+=temp.second;
            finish_time[1]+=temp.second;
            for(auto i=map2.begin();i!=map2.end()&&*i<=finish_time[1];i++)
            {
                    no_waiting[1]++;                        //no. of passengers waiting in queue2
            }
            map2.erase(map2.begin());
            q2.pop();


        }
        if(!q3.empty())                                     //if queue3 is not empty i.e. it has some passengers
        {
            pair<double,double> temp=q3.front();

             
          
            if(temp.first<finish_time[2])
                wait_time[2]+=finish_time[2]-temp.first;

            if(!q1.empty())                                 //if queue1 is not empty i.e. it has some passengers
            {
                if(q1.front().first<=finish_time[0])
                    inspected++;                            //passenger got inspected from queue
            }
            if(!q2.empty())                                 //if queue2 is not empty i.e. it has some passengers
            {
                if(q2.front().first<=finish_time[1])
                    inspected++;                            //passenger got inspected from queue
            }
            if(!q3.empty())                                 //if queue3 is not empty i.e. it has some passengers
            {
                if(q3.front().first<=finish_time[2])    
                    inspected++;                            //passenger got inspected from queue
            }
            if(temp.first>=finish_time[2])
            {
                finish_time[2]=temp.first;
            }
           
            ser_time[2]+=temp.second;
            finish_time[2]+=temp.second;
             
           for(auto i=map3.begin();i!=map3.end()&&*i<=finish_time[2];i++)
            {
                    no_waiting[2]++;                        //no. of passengers waiting in queue3
            }  
              map3.erase(map3.begin());
            q3.pop();

        }

        int index=0;
       
    }

    inspected=inspected/(3*n);                                                                      //average no. of passengers getting inspected
    double avg_wt=((wait_time[0])/n+(wait_time[1])/n+(wait_time[2])/n);                             //average waiting time for all passengers
    double avg_st=((ser_time[0])/n+(ser_time[1])/n+(ser_time[2])/n)/3;                              //average service time for all queues
    double avg_rt=avg_wt+avg_st;                                                                    //average response time for all passengers
    double waiting=((no_waiting[0])+(no_waiting[1])+(no_waiting[2]))/(3*n);                         //average no. of passengers waiting in queues

    cout<<"Avg no of inspected passenges : "<<inspected<<" passenger/sec"<<endl;
    cout<<"Avg response time : "<<avg_rt<<" seconds"<<endl;
    cout<<"Avg Waiting time : "<<avg_wt<<" seconds"<<endl;
   
    cout<<"Avg no of passenger waiting :"<<waiting<<" passenger/sec"<<endl;
 
}



void case_B(double arrival_rate,double service_rate,float hour)               //This function is used to implement the case B of the problem.
{
   if(service_rate<arrival_rate)                                           //Arrival rate must be greater than service rate to be in steady state
    {
        cout<<"Arrival rate must be greater than service rate to be in stable state\n ";
        return;
    }

    double n=hour;
    double inspected=0,arrival[3]={0};
    srand((unsigned)time(0));
    queue<pair<double,double>> q1;
    double finish_time[3]={0},wait_time[3]={0},ser_time[3]={0},no_waiting=0;
    vector<double> map1;
    for(long int i=1;i<=n;i++)
    {
        double at=poisson_distributed_random_variables(3600/arrival_rate);                            //poisson distributed arrival time
        double st=exponentially_distributed_random_variables(3600/service_rate);                      //exponentially distributed service time
        at=at+arrival[0];
        q1.push(make_pair(at,st));
        map1.push_back(at);
        arrival[0]=at;
    }
    cout<<"\nplease wait ........\n";
     int j=0;
    while(true)
    {
        if(q1.empty())                               //if queue1 is not empty i.e. it has some passengers
        {
            break;
        }
         
        for(auto i=map1.begin();i!=map1.end()&&*i<=finish_time[j];i++)
        {
            no_waiting++;                            //no. of passengers waiting in queue
        }
        
        pair<double,double> temp=q1.front();
        
        if(temp.first<finish_time[j])
            wait_time[j]+=finish_time[j]-temp.first;
        
       if(q1.front().first<=finish_time[0])
            inspected++;                             //passenger got inspected from queue
        if(q1.front().first<=finish_time[1])
            inspected++;                             //passenger got inspected from queue
        if(temp.first>=finish_time[j])
        {
            finish_time[j]=temp.first;
        }
        
        
         
        if(q1.front().first<=finish_time[2])
            inspected++;                             //passenger got inspected from queue
        map1.erase(map1.begin());  //see here
        ser_time[j]+=temp.second;
        finish_time[j]+=temp.second;
        
        q1.pop();

       j=(j+1)%3;
      
    }


    inspected=(inspected/(n));                                                  //average no. of passengers getting inspected
    double avg_wt=((wait_time[0])+(wait_time[1])+(wait_time[2]))/n;             //average waiting time for all passengers
    double avg_st=((ser_time[0])+(ser_time[1])+(ser_time[2]))/n;                //average service time for all officers
    double avg_rt=avg_wt+avg_st;                                                //average response time for all passengers
    double waiting=no_waiting/n;                                                //average no. of passengers waiting in queue

    cout<<"Avg no of inspected passenges : "<<inspected<<" passenger/sec"<<endl;
    cout<<"Avg response time : "<<avg_rt<<" seconds"<<endl;
    cout<<"Avg Waiting time : "<<avg_wt<<" seconds"<<endl;
   
    cout<<"Avg no of passenger waiting :"<<waiting<<" passenger/sec"<<endl;
}

void case_C(double arrival_rate,double service_rate,float hour)               //This function is used to implement the case C of the problem.
{
    arrival_rate=arrival_rate/3;
    if(service_rate<=arrival_rate)                                          //Arrival rate must be greater than service rate to be in steady state
    {
        cout<<"Arrival rate must be greater than service rate to be in stable state\n ";
        return;
    }

    double n=hour;
    double inspected=0,arrival[3]={0};
    srand((unsigned)time(0));
    queue<pair<double,double>> q1,q2,q3,chair_q1,chair_q2,chair_q3;
    double finish_time[3]={0},wait_time[3]={0},ser_time[3]={0},no_waiting[3]={0};
    for(long int i=0;i<n;i++)
    {   
        //FOR QUEUE1
        double at=poisson_distributed_random_variables(3600/arrival_rate);                  //poisson distributed arrival time          
        double st=exponentially_distributed_random_variables(3600/service_rate);            //exponentially distributed service time
        at=at+arrival[0];
        q1.push(make_pair(at,st));                                                          //putting passenger in queue1
        arrival[0]=at;

        //FOR QUEUE2
        at=poisson_distributed_random_variables(3600/arrival_rate);                         //poisson distributed arrival time
        st=exponentially_distributed_random_variables(3600/service_rate);                   //exponentially distributed service time
         at=at+arrival[1];
        q2.push(make_pair(at,st));                                                          //putting passenger in queue2
        arrival[1]=at;

        //FOR QUEUE3
        at=poisson_distributed_random_variables(3600/arrival_rate);                         //poisson distributed arrival time
        st=exponentially_distributed_random_variables(3600/service_rate);                   //exponentially distributed service time
         at=at+arrival[2];
        q3.push(make_pair(at,st));                                                          //putting passenger in queue3
        arrival[2]=at;

    }
    finish_time[0]=q1.front().second+q1.front().first;
    finish_time[1]=q2.front().second+q2.front().first;
    finish_time[2]=q3.front().second+q3.front().first;
    int start0=0,start1=0,start2=0,count1=0,count2=0,count3=0;
    while (true)
    {
        if(q1.empty()&&q2.empty()&&q3.empty())                      //if all the queues are empty i.e. no passenger at all
            break;

                            //******************************* FOR QUEUE 1 *****************************

        while(chair_q1.size()<10&&(!q1.empty())&&q1.front().first<=finish_time[0])
        {
            if(count1==100)                 //maintaining a count to drop every 100th passenger into a regular queue
            {
                q1.pop();
                count1=0;
                if(q1.front().first>finish_time[0])
                    finish_time[0]=q1.front().first;

                continue;
            }
            chair_q1.push(q1.front());          //putting the passenger on chair on queue1
            q1.pop();
            count1++;                           //passenger got inspected from queue    
        }
        if(!chair_q1.empty())                   //if there is some passenger sitting on chair of queue1
        {
            if(chair_q1.front().first<finish_time[0])
                inspected++;                    //passenger got inspected from queue
            if(start0==0)
            {
                finish_time[0]=chair_q1.front().first;
                start0=1;
            }
            no_waiting[0]+=chair_q1.size();             //no. of passengers waiting in queue1    

            pair<double,double> temp=chair_q1.front();

             if(temp.first<finish_time[0])
                wait_time[0]+=finish_time[0]-temp.first;            //computing waiting time
        
            if(temp.first>=finish_time[0])
            {
                finish_time[0]=temp.first;                          //computing finish time
            }
            
             ser_time[0]+=temp.second;
            finish_time[0]+=temp.second;
           
            chair_q1.pop();
            if(chair_q1.size()==0&&q1.front().first>=finish_time[0])
                finish_time[0]=q1.front().first;
        }

                            //******************************* FOR QUEUE 2 *****************************

        while(chair_q2.size()<10&&(!q2.empty())&&q2.front().first<=finish_time[1])
        {
            if(count2==100)                                 //maintaining a count to drop every 100th passenger into a regular queue
            {                                               
                q2.pop();
                count2=0;
                if(q2.front().first>finish_time[1])
                    finish_time[1]=q2.front().first;
                continue;
            }
            chair_q2.push(q2.front());              //putting the passenger on chair on queue2
            q2.pop();
            count2++;
        }
        if(!chair_q2.empty())                       //if there is some passenger sitting on chair of queue2
        {
            if(chair_q2.front().first<finish_time[1])
                inspected++;                        //passenger got inspected from queue
            if(start1==0)
            {
                finish_time[1]=chair_q2.front().first;
                start1=1;
            }
            no_waiting[1]+=chair_q2.size();             //no. of passengers waiting in queue2

            pair<double,double> temp=chair_q2.front();


             if(temp.first<finish_time[1])
                wait_time[1]+=finish_time[1]-temp.first;                //computing waiting time
        
            if(temp.first>=finish_time[1])
            {
                finish_time[1]=temp.first;                              //computing finish time
            }
           
             ser_time[1]+=temp.second;
            finish_time[1]+=temp.second;
            
            chair_q2.pop();
            if(chair_q2.size()==0&&q2.front().first>=finish_time[1])
                finish_time[1]=q2.front().first;
        }

                                //******************************* FOR QUEUE 3 *****************************

        while(chair_q3.size()<10&&(!q3.empty())&&q3.front().first<=finish_time[2])
        {
            if(count3==100)
            {
                q3.pop();
                count3=0;
                if(q3.front().first>finish_time[2])
                    finish_time[2]=q3.front().first;
                continue;
            }
            chair_q3.push(q3.front());                      //putting the passenger on chair on queue3

            q3.pop();
            count3++;                                       //passenger got inspected from queue
        }
        if(!chair_q3.empty())                               //if there is some passenger sitting on chair of queue3
        {
             if(chair_q3.front().first<finish_time[2])
                inspected++;                                //passenger got inspected from queue
            if(start2==0)
            {
                finish_time[2]=chair_q3.front().first;
                start2=1;
            }
            no_waiting[2]+=chair_q3.size();                //no. of passengers waiting in queue3     

            pair<double,double> temp=chair_q3.front();

             if(temp.first<finish_time[2])
                wait_time[2]+=finish_time[2]-temp.first;        //computing waiting time
            
            if(temp.first>=finish_time[2])
            {
                finish_time[2]=temp.first;              //computing finish time
            }
            
             ser_time[2]+=temp.second;
            finish_time[2]+=temp.second;                    //computing finish time
           
            chair_q3.pop();
            if(chair_q3.size()==0&&q3.front().first>=finish_time[2])
                finish_time[2]=q3.front().first;
        } 
        
    }


    inspected=inspected/(3*n);                                                      //average no. of passengers getting inspected
    double avg_wt=((wait_time[0])/n+(wait_time[1])/n+(wait_time[2])/n);             //average waiting time for all passengers
    double avg_st=((ser_time[0])/n+(ser_time[1])/n+(ser_time[2])/n)/3;              //average service time for all queues
    double avg_rt=avg_wt+avg_st;                                                    //average response time for all passengers
    double waiting=((no_waiting[0])+(no_waiting[1])+(no_waiting[2]))/(3*n);         //average no. of passengers waiting in queues

    cout<<"Avg no of inspected passenges : "<<inspected<<" passenger/sec"<<endl;
    cout<<"Avg response time : "<<avg_rt<<" seconds"<<endl;
    cout<<"Avg Waiting time : "<<avg_wt<<" seconds"<<endl;
   
    cout<<"Avg no of passenger waiting :"<<waiting<<" passenger/sec"<<endl;
 
}


int main()
{
    char op;                            
   
    float arrival_rate=0,service_rate=0,h=60000;
    
    char ch='N';
    do
    {
         cout<<"select the case A/B/C/E:  ";                                    //providing options to user for choosing cases A/B/C or E for EXIT
         cin>>op;
        
        switch (op)
        {
            case 'A':                                                           //case A is chosen by the user
            {
                cout<<"Enter arrival rate (λ in hour/passenger) : ";            
                cin>>arrival_rate;                                              //arrival rate1
                cout<<"Enter service rate (µ in hour/passenger) : ";
                cin>>service_rate;                                              //service rate1
                case_A(arrival_rate,service_rate,h);
                cout<<"\nDo YOU WANT TO CONTINUE TYPE Y/N :";
                cin>>ch;
                break;
            }
            case 'B':                                                           //case B is chosen by the user
            {
                cout<<"Enter arrival rate (λ in hour/passenger) : ";
                cin>>arrival_rate;                                              //arrival rate2
                cout<<"Enter service rate (µ in hour/passenger) : ";
                cin>>service_rate;                                              //service rate2
                case_B(arrival_rate,service_rate,h);
                cout<<"\nDo YOU WANT TO CONTINUE TYPE Y/N :";
                cin>>ch;
                break;
            }
            case 'C':                                                           //case C is chosen by the user
            {
                cout<<"Enter arrival rate (λ in hour/passenger) : ";
                cin>>arrival_rate;                                              //arrival rate3
                cout<<"Enter service rate (µ in hour/passenger) : ";
                cin>>service_rate;                                              //service rate3
                case_C(arrival_rate,service_rate,h);
                cout<<"\nDo YOU WANT TO CONTINUE TYPE Y/N :";
                cin>>ch;
                break;
            }
            case 'E':                                                           //for EXIT
            {
                exit(0);
                break;
            }
            default:                                                            //for handling invalid options
               { cout<<"Invalid option selection  Try again!\n";
                ch='Y';
                fflush(stdin);
                break;
               }
        }
    }while(ch=='Y'||ch=='y');
    
    return 0;
}