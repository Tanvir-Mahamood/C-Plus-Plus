#include<bits/stdc++.h>
using namespace std;
string p="1100";
string q="1010";
string np="0011";
string nq="0101";

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

string solve(string str)
{
    int i,j;
    string temp,ans,opp,PP,QQ,gans,gtemp,gntemp;
    vector<string> vs;

    for(i=0;i<str.size();i++)
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

    for(i=0;i<vs.size();i++)
    {
        opp=vs[i];

        if(opp.size()==3 && opp[1]=='a') ans=andxy(p,q);
        else if(opp.size()==3 && opp[1]=='o') ans=orxy(p,q);
        else if(opp.size()==3 && opp[1]=='c')
        {
            if(opp[0]=='p') ans=condxy(p,q);
            else ans=condxy(q,p);
        }
        else if(opp.size()==3 && opp[1]=='b') ans=bicondxy(p,q);

        else if(opp.size()==4 && opp[0]=='n' && opp[1]=='p')
        {
            PP=np;
            QQ=q;
            if(opp[2]=='a') ans=andxy(PP,QQ);
            else if(opp[2]=='o') ans=orxy(PP,QQ);
            else if(opp[2]=='c') ans=condxy(PP,QQ);
            else if(opp[2]=='b') ans=bicondxy(PP,QQ);
        }
        else if(opp.size()==4 && opp[0]=='n' && opp[1]=='q')
        {
            PP=p;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(QQ,PP);
            else if(opp[2]=='o') ans=orxy(QQ,PP);
            else if(opp[2]=='c') ans=condxy(QQ,PP);
            else if(opp[2]=='b') ans=bicondxy(QQ,PP);
        }

        else if(opp.size()==4 && opp[2]=='n' && opp[3]=='q')
        {
            PP=p;
            QQ=nq;
            if(opp[1]=='a') ans=andxy(PP,QQ);
            else if(opp[1]=='o') ans=orxy(PP,QQ);
            else if(opp[1]=='c') ans=condxy(PP,QQ);
            else if(opp[1]=='b') ans=bicondxy(PP,QQ);
        }
        else if(opp.size()==4 && opp[2]=='n' && opp[3]=='p')
        {
            PP=np;
            QQ=q;
            if(opp[1]=='a') ans=andxy(QQ,PP);
            else if(opp[1]=='o') ans=orxy(QQ,PP);
            else if(opp[1]=='c') ans=condxy(QQ,PP);
            else if(opp[1]=='b') ans=bicondxy(QQ,PP);
        }

        else if(opp.size()==5 && opp[1]=='p')
        {
            PP=np;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(PP,QQ);
            else if(opp[2]=='o') ans=orxy(PP,QQ);
            else if(opp[2]=='c') ans=condxy(PP,QQ);
            else if(opp[2]=='b') ans=bicondxy(PP,QQ);
        }
        else if(opp.size()==5 && opp[1]=='q')
        {
            PP=np;
            QQ=nq;
            if(opp[2]=='a') ans=andxy(QQ,PP);
            else if(opp[2]=='o') ans=orxy(QQ,PP);
            else if(opp[2]=='c') ans=condxy(QQ,PP);
            else if(opp[2]=='b') ans=bicondxy(QQ,PP);
        }

        else if(opp.size()==1 || opp.size()==2) ans=opp;

        vs[i]=ans;
    }

    gntemp=vs[0];
    if(gntemp.size()==1)
    {
        vs[1]=negxy(vs[1]);
    }
    gntemp.clear();

    for(i=1;i<vs.size();i++)
    {
        gntemp=vs[i];
        if(gntemp.size()==2)
        {
            vs[i+1]=negxy(vs[i+1]);
            vs[i]=gntemp[0];
        }
    }

    for(i=0;i<vs.size();i++)
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
    return gans;
}

int main()
{
    string str1,str2,res1,res2;

    getline(cin,str1);
    str1.erase(remove_if(str1.begin(),str1.end(),::isspace),str1.end());

    getline(cin,str2);
    str2.erase(remove_if(str2.begin(),str2.end(),::isspace),str2.end());

    res1=solve(str1);
    res2=solve(str2);

    (res1==res2)?cout<<"Equivalent\n":cout<<"Not Equivalent\n";

    return 0;
}




