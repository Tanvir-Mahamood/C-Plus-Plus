#include<bits/stdc++.h>
using namespace std;
string p="1100";
string q="1010";
string np="0011";
string nq="0101";

int ck(string ans)
{
    int sum=0;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]=='1') sum++;
    }
    return sum;
}

string andxy(string opp1,string opp2)
{
    int i;
    string res;

    for(i=0;i<4;i++)
    {
        if(opp1[i]=='1' && opp2[i]=='1') res.push_back('1');
        else res.push_back('0');
    }

    return res;
}
string orxy(string opp1,string opp2)
{
    int i;
    string res;

    for(i=0;i<4;i++)
    {
        if(opp1[i]=='0' && opp2[i]=='0') res.push_back('0');
        else res.push_back('1');
    }

    return res;
}
string condxy(string opp1,string opp2)
{
    int i;
    string res;

    for(i=0;i<4;i++)
    {
        if(opp1[i]=='1' && opp2[i]=='0') res.push_back('0');
        else res.push_back('1');
    }

    return res;
}
string bicondxy(string opp1,string opp2)
{
    int i;
    string res;

    for(i=0;i<4;i++)
    {
        if(opp1[i]==opp2[i]) res.push_back('1');
        else res.push_back('0');
    }

    return res;
}
string negxy(string opp)
{
    for(int i=0;i<4;i++)
    {
        if(opp[i]=='1') opp[i]='0';
        else opp[i]='1';
    }
    return opp;
}

int solve(string str)
{
    int i,j,cnt;
    string temp,ans,opp,PP,QQ,gans,gtemp,gntemp;
    vector<string> vs;

    for(i=0;i<str.size();i++) //String Separation
    {
        if(str[i]=='(')
        {
            i++;
            while(str[i] != ')')
            {
                temp.push_back(str[i]);
                i++;
            }
            vs.push_back(temp);
            temp.clear();
            i--;
        }
        else if(str[i]==')' && (i != (str.size()-1)))
        {
            i++;
            while(str[i] != '(')
            {
                temp.push_back(str[i]);
                i++;
            }
            vs.push_back(temp);
            temp.clear();
            i--;
        }
        else if(i==0)
        {
            while(str[i] != '(')
            {
                temp.push_back(str[i]);
                i++;
            }
            vs.push_back(temp);
            temp.clear();
            i--;
        }
    }

    for(i=0;i<vs.size();i++) //Creating Commands
    {
        opp=vs[i];

        //Story of 3
        if(opp.size()==3 && opp[1]=='a')
        {
            if(opp[0]=='p' && opp[2]=='p') ans=andxy(p,p);
            else if(opp[0]=='p' && opp[2]=='q') ans=andxy(p,q);
            else if(opp[0]=='q' && opp[2]=='p') ans=andxy(q,p);
            else if(opp[0]=='q' && opp[2]=='q') ans=andxy(q,q);
        }
        else if(opp.size()==3 && opp[1]=='o')
        {
            if(opp[0]=='p' && opp[2]=='p') ans=orxy(p,p);
            else if(opp[0]=='p' && opp[2]=='q') ans=orxy(p,q);
            else if(opp[0]=='q' && opp[2]=='p') ans=orxy(q,p);
            else if(opp[0]=='q' && opp[2]=='q') ans=orxy(q,q);
        }
        else if(opp.size()==3 && opp[1]=='c')
        {
            if(opp[0]=='p' && opp[2]=='p') ans=condxy(p,p);
            else if(opp[0]=='p' && opp[2]=='q') ans=condxy(p,q);
            else if(opp[0]=='q' && opp[2]=='p') ans=condxy(q,p);
            else if(opp[0]=='q' && opp[2]=='q') ans=condxy(q,q);
        }
        else if(opp.size()==3 && opp[1]=='b')
        {
            if(opp[0]=='p' && opp[2]=='p') ans=bicondxy(p,p);
            else if(opp[0]=='p' && opp[2]=='q') ans=bicondxy(p,q);
            else if(opp[0]=='q' && opp[2]=='p') ans=bicondxy(q,p);
            else if(opp[0]=='q' && opp[2]=='q') ans=bicondxy(q,q);
        }

        //story of 4
        else if(opp.size()==4 && opp[0]=='n' && opp[1]=='p' && opp[3]=='q') //np*q
        {
            PP=np;
            QQ=q;
            if(opp[2]=='a') ans=andxy(PP,QQ);
            else if(opp[2]=='o') ans=orxy(PP,QQ);
            else if(opp[2]=='c') ans=condxy(PP,QQ);
            else if(opp[2]=='b') ans=bicondxy(PP,QQ);
        }
        else if(opp.size()==4 && opp[0]=='n' && opp[1]=='p' && opp[3]=='p') //np*p
        {
            PP=np;
            //QQ=q;
            if(opp[2]=='a') ans=andxy(PP,p);
            else if(opp[2]=='o') ans=orxy(PP,p);
            else if(opp[2]=='c') ans=condxy(PP,p);
            else if(opp[2]=='b') ans=bicondxy(PP,p);
        }
        else if(opp.size()==4 && opp[0]=='n' && opp[1]=='q' && opp[3]=='p') //nq*p
        {
            PP=p;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(QQ,PP);
            else if(opp[2]=='o') ans=orxy(QQ,PP);
            else if(opp[2]=='c') ans=condxy(QQ,PP);
            else if(opp[2]=='b') ans=bicondxy(QQ,PP);
        }
        else if(opp.size()==4 && opp[0]=='n' && opp[1]=='p' && opp[3]=='p') //nq*q
        {
            //PP=np;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(QQ,q);
            else if(opp[2]=='o') ans=orxy(QQ,q);
            else if(opp[2]=='c') ans=condxy(QQ,q);
            else if(opp[2]=='b') ans=bicondxy(QQ,q);
        }
        /*else if(opp.size()==4 && opp[0]=='n' && opp[1]=='q')
        {
            PP=p;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(QQ,PP);
            else if(opp[2]=='o') ans=orxy(QQ,PP);
            else if(opp[2]=='c') ans=condxy(QQ,PP);
            else if(opp[2]=='b') ans=bicondxy(QQ,PP);
        }*/

        else if(opp.size()==4 && opp[2]=='n' && opp[0]=='p' && opp[3]=='q') //p*nq
        {
            PP=p;
            QQ=nq;
            if(opp[1]=='a') ans=andxy(PP,QQ);
            else if(opp[1]=='o') ans=orxy(PP,QQ);
            else if(opp[1]=='c') ans=condxy(PP,QQ);
            else if(opp[1]=='b') ans=bicondxy(PP,QQ);
        }
        else if(opp.size()==4 && opp[2]=='n' && opp[0]=='p' && opp[3]=='p') //p*np
        {
            PP=np;
            //QQ=nq;
            if(opp[1]=='a') ans=andxy(p,PP);
            else if(opp[1]=='o') ans=orxy(p,PP);
            else if(opp[1]=='c') ans=condxy(p,PP);
            else if(opp[1]=='b') ans=bicondxy(p,PP);
        }
        else if(opp.size()==4 && opp[2]=='n' && opp[0]=='q' && opp[3]=='q') //q*np
        {
            PP=np;
            QQ=q;
            if(opp[1]=='a') ans=andxy(QQ,PP);
            else if(opp[1]=='o') ans=orxy(QQ,PP);
            else if(opp[1]=='c') ans=condxy(QQ,PP);
            else if(opp[1]=='b') ans=bicondxy(QQ,PP);
        }
        else if(opp.size()==4 && opp[2]=='n' && opp[0]=='q' && opp[3]=='q') //q*nq
        {
            //PP=np;
            QQ=nq;
            if(opp[1]=='a') ans=andxy(QQ,p);
            else if(opp[1]=='o') ans=orxy(QQ,p);
            else if(opp[1]=='c') ans=condxy(QQ,p);
            else if(opp[1]=='b') ans=bicondxy(QQ,p);
        }


        //story of 5
        else if(opp.size()==5 && opp[1]=='p' && opp[4]=='q')
        {
            PP=np;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(PP,QQ);
            else if(opp[2]=='o') ans=orxy(PP,QQ);
            else if(opp[2]=='c') ans=condxy(PP,QQ);
            else if(opp[2]=='b') ans=bicondxy(PP,QQ);
        }
        else if(opp.size()==5 && opp[1]=='p' && opp[4]=='p')
        {
            PP=np;
            //QQ=nq;
            if(opp[2]=='a') ans=andxy(PP,PP);
            else if(opp[2]=='o') ans=orxy(PP,PP);
            else if(opp[2]=='c') ans=condxy(PP,PP);
            else if(opp[2]=='b') ans=bicondxy(PP,PP);
        }
        else if(opp.size()==5 && opp[1]=='q' && opp[4]=='p')
        {
            PP=np;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(QQ,PP);
            else if(opp[2]=='o') ans=orxy(QQ,PP);
            else if(opp[2]=='c') ans=condxy(QQ,PP);
            else if(opp[2]=='b') ans=bicondxy(QQ,PP);
        }
        else if(opp.size()==5 && opp[1]=='q' && opp[4]=='q')
        {
            //PP=np;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(QQ,QQ);
            else if(opp[2]=='o') ans=orxy(QQ,QQ);
            else if(opp[2]=='c') ans=condxy(QQ,QQ);
            else if(opp[2]=='b') ans=bicondxy(QQ,QQ);
        }

        //story of 1 and 2
        else if(opp.size()==1 || opp.size()==2) ans=opp;

        vs[i]=ans;
    }
    //Command is ready

    //front negation adjustmant
    gntemp=vs[0];
    if(gntemp.size()==1)
    {
        vs[1]=negxy(vs[1]);
    }
    gntemp.clear();
    //inner negation adjustment
    for(i=1;i<vs.size();i++)
    {
        gntemp=vs[i];
        if(gntemp.size()==2)
        {
            vs[i+1]=negxy(vs[i+1]);
            vs[i]=gntemp[0];
        }
    }


    //for(i=0;i<vs.size();i++) cout<<vs[i]<<" ";

    for(i=0;i<vs.size();i++) //Final Operation
    {
        gtemp=vs[i];
        if(gtemp.size()==1 && gtemp[0]=='a')
        {
            if(gans.size()==0) gans=andxy(vs[i-1],vs[i+1]);
            else gans=andxy(gans,vs[i+1]);
            i++;
        }
        else if(gtemp.size()==1 && gtemp[0]=='o')
        {
            if(gans.size()==0) gans=orxy(vs[i-1],vs[i+1]);
            else gans=orxy(gans,vs[i+1]);
            i++;
        }
        else if(gtemp.size()==1 && gtemp[0]=='c')
        {
            if(gans.size()==0) gans=condxy(vs[i-1],vs[i+1]);
            else gans=condxy(gans,vs[i+1]);
            i++;
        }
        else if(gtemp.size()==1 && gtemp[0]=='b')
        {
            if(gans.size()==0) gans=bicondxy(vs[i-1],vs[i+1]);
            else gans=bicondxy(gans,vs[i+1]);
            i++;
        }

        else if(vs.size()==1 || vs.size()==2) gans=gtemp;
    }
//cout<<gans<<endl;
    cnt=ck(gans);
    return cnt;
}

int main()
{
    string str;
    int ans;
    getline(cin,str);
    str.erase(remove_if(str.begin(),str.end(),::isspace),str.end());
    ans=solve(str);
    if(ans==4) cout<<"Truthful Yudhisthira\n";
    else if(ans==0) cout<<"Eternal Liar\n";
    else cout<<"Human";
    return 0;
}
//(paq)c(npoq)



