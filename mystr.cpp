#include <iostream>

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include <vector>

using namespace std;

class String
{
	private:
		vector<char> line;
	public:
		String(){};
		
		String(const String& q)
		{
			for(int i=0; i< q.line.size(); i++)
				line.push_back(q.line[i]);
		}
		
		String(const char* a)
		{
			for(int i=0; i<strlen(a); i++)
				line.push_back(a[i]);
		}
	
		friend istream& operator>>(istream&, String&);
		friend ostream& operator<<(ostream&, const String&);

		String Sum(const String& a,const String& b)
		{
			String c;
			for(int i=0; i<a.line.size(); i++)
				c.line.push_back(a.line[i]);
			for(int i=0; i<b.line.size(); i++)
				c.line.push_back(b.line[i]);
			return(c);
		}
		
		int Cmp(const String& a, const String& b)
		{
			int i=0;
			while((a.line[i]==b.line[i]) && (i<a.line.size()) && (i<b.line.size())) i++;
			if(a.line[i]>b.line[i]) return(1);
			if(a.line[i]<b.line[i]) return(-1);
			if((a.line[i]==b.line[i]) && (a.line.size()>b.line.size())) return(1);
			if((a.line[i]==b.line[i]) && (a.line.size()<b.line.size())) return(-1);		
			if((a.line[i]==b.line[i]) && (a.line.size()==b.line.size())) return(0);
		}

		void PushBack(char c)
		{
			line.push_back(c);
		}

		void PopBack()
		{
			line.pop_back();
		}
		
		void PopFrom(int i)
		{
			for(int j=i; j<line.size()-1; j++)
				line[j]=line[j+1];
			line.pop_back();
		}
		
		void PushInto(int i, char c)
		{
			line.push_back('0');
			for( int j=line.size()-1; j>i; j--)
				line[j]=line[j-1];
			line[i]=c;
		}

		char operator[](int i)
		{
			return(line[i]);
		};

		int Size()
		{
			return(line.size());
		}
			
};

istream& operator>>(istream& is,String& s)
{
	char c;
	is>>c;
	while(c!='\n')
	{
		s.line.push_back(c);
		c=getchar();
	}		
	return(is);
}	

ostream& operator<<(ostream& os, const String& s)
{
	for(int i=0;i<s.line.size(); i++)
		os<<s.line[i];
	return os;
}

int test1()
{
	String r("Добрый день.");
	String c("Реализация класса строк.");
	c=c.Sum(r,c);
	for(int i=r.Size()-1; i>=0; i--)
		c.PopFrom(i);
	const char* s ="Здравствуйте.";
	for(int i=0;i<strlen(s);i++)
		c.PushInto(i,s[i]);
	String q("Здравствуйте.Реализация класса строк.");
	return(1-c.Cmp(c,q));
}	
	
int test2()
{	
	String r("glksrglsgnsk gnel nglskeg nsog 3ion lgn gs3-2=5986");
	String c(r);
	for(int i=r.Size()-1; i>=5; i--)
		r.PopFrom(i);
	for(int i=0;i<5;i++)
		c.PushBack(r[i]);
	String q("glksrglsgnsk gnel nglskeg nsog 3ion lgn gs3-2=5986glksr");
	return(1-c.Cmp(c,q));
}

int main()
{
	cout<<test1()<<" "<<test2();
	return(0);
	
}
