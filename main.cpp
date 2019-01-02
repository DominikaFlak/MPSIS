#include <iostream>
#include <string>
#include <fstream>
#include <iostream> 
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include <vector>


#include "cgicc/CgiDefs.h"



using namespace std;
using namespace cgicc;



int main( int argc, char ** argv, char ** envp )
{
    
    //string wierzcholki = "24";
    string wierzcholki;
    //string krawedzie = "53";
     string krawedzie;
    //string odcinek = "10";
     string odcinek;
    //string pokrycie = "100";
      string pokrycie;
    
     
    string line;
    
     system("cp kopiaMOD.mod workfile.mod");

 

    try
    {
          
             Cgicc formData;

       // Send HTTP header: Content-type: text/html
       cout << HTTPHTMLHeader() << endl;

       // Print: <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd">
       cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;

       // Print: <html lang="en" dir="LTR">
       cout << html().set("lang", "EN").set("dir", "LTR") << endl;

       // Set up the HTML document
       cout << html() << head() << title("Optimize the costs of bulding highway") << head() << endl;
    
         cout << body().set("background","images/content-bg.jpg").set("text","#ffffff").set("link","#0000ff").set("vlink","#000080") << endl;



       cout << h1("Building highway? Find out how to optimize the costs!") << endl;

       form_iterator fvalue1 = formData.getElement("value1");
       if( !fvalue1->isEmpty() && fvalue1 != (*formData).end()) {
         // cout << "Value1: " << **fvalue1 << endl;
          wierzcholki = **fvalue1;
          cout << "<br>" << "<br>" << "<b>" << "Value1: "<< "</b>" << wierzcholki << endl;
       }
       else
          cout << "No text entered for value1" << endl;
//----------------------------------
    /*     form_iterator fvalue2 = formData.getElement("value2");
       if( !fvalue2->isEmpty() && fvalue2 != (*formData).end()) {
          cout << "Value2: " << **fvalue2 << endl;
          krawedzie = **fvalue2;
       }
       else
          cout << "No text entered for value2" << endl;    */
    
     if (wierzcholki == "8" ){
          krawedzie = "13" ; }
     else if( wierzcholki == "12") {
          krawedzie = "23"; }
     else if (wierzcholki == "16") {
          krawedzie = "33"; }
     else if (wierzcholki == "20") {
          krawedzie = "43"; }
     else if (wierzcholki == "24") {
          krawedzie = "53"; }
       
        cout << "<b>" <<"Value2: "<< "</b>" << krawedzie << "\n" << endl;



//----------------------------------
        form_iterator fvalue3 = formData.getElement("value3");
       if( !fvalue3->isEmpty() && fvalue3 != (*formData).end()) {
          cout << "<b>" <<"Value3: " <<"</b>" << **fvalue3 << "\n" << endl;
          odcinek = **fvalue3;
       }
       else
          cout << "No text entered for value3" << endl;
//----------------------------------
        form_iterator fvalue4 = formData.getElement("value4");
       if( !fvalue4->isEmpty() && fvalue4 != (*formData).end()) {
          cout << "<b>" << "Value4: " <<"</b>" << **fvalue4 << "\n" << "<br>" << "<br>";
          pokrycie = **fvalue4;
       }
       else
          cout << "No text entered for value4" << endl;

//-------------------------------------------------------------------------
        fstream myFile("workfile.mod", ios::in | ios::out); 
    
   
    myFile.seekg(2161, ios::beg); 
      
   
    
    myFile <<  "param V_count := " + wierzcholki + ';'+"\n";
    myFile <<  "param E_count := " + krawedzie + ';'+"\n";
    myFile <<  "param odc := " + odcinek + ';'+"\n";
    myFile <<  "param pokrycie := " + pokrycie + ';'+"\n";
    myFile <<  "param : h  s t :=\n  1      1 1 " + wierzcholki +"\n"+';'+"\n";
    //-------------------------------------------------------------------------
               ifstream myfile ("paramA.txt");
               int krawedz= atoi(krawedzie.c_str());
              if (myfile.is_open())
                    {
                  
                 for (int i =0; i < krawedz +1 ; i++ )
                  {
      
                   getline (myfile,line);
                   myFile << line + "\n";
      
                   }
                  myFile << ";";
		  myFile << "\n";
                  myfile.close();
                      }
               else cout << "Unable to open file"; 
   //-------------------------------------------------------------------------
           ifstream myfile2 ("paramB.txt");
              if (myfile2.is_open())
                    {
                  
                 for (int i =0; i < krawedz +1 ; i++ )
                  {
      
                   getline (myfile2,line);
                   myFile << line + "\n";
     
                   }
                  myFile << ';';
		myFile << "\n";
                  myfile2.close();
                      }
               else cout << "Unable to open file"; 
   //-------------------------------------------------------------------------
           ifstream myfile3 ("grunt.txt");
              if (myfile3.is_open())
                    {
                  
                 for (int i =0; i < krawedz + 1 ; i++ )
                  {
      
                   getline (myfile3,line);
                     myFile << line + "\n";
     
                   }
                  myFile << ';';
		 myFile << "\n";
                  myfile3.close();
                      }
               else cout << "Unable to open file"; 
   //-------------------------------------------------------------------------
           ifstream myfile4 ("BTS.txt");
              if (myfile4.is_open())
                    {
                  
                 for (int i =0; i < krawedz + 1 ; i++ )
                  {
      
                   getline (myfile4,line);
                   myFile << line + "\n";
     
                   }
                  myFile << ';';
		 myFile << "\n";
                  myfile4.close();
                      }
               else cout << "Unable to open file"; 
   //-------------------------------------------------------------------------
           ifstream myfile5 ("KSI.txt");
              if (myfile5.is_open())
                    {
                  
                 for (int i =0; i < krawedz + 1 ; i++ )
                  {
      
                   getline (myfile5,line);
                   myFile << line + "\n";
     
                   }
       		myFile << ';';
		myFile << "\n";
                  myfile5.close();
                      }
               else cout << "Unable to open file"; 


//-------------------------------------------------------------------------
  
            myFile << "end;\n";
    
           myFile.close(); 
//-------------------------------------------------------------------------


  system("cbc workfile.mod% -solve -solu wynik.txt >> output.txt");

    string line;
//-------------------------------------------------------------------------
 

    ifstream myfile6 ("wynik.txt");
              if (myfile6.is_open())
                    {
                  
                  while (! myfile6.eof() )
                  {
      
                  
                   while (getline(myfile6, line) && line.find("u[") == string::npos){
                   cout << line + "\n" + "<br>";       }
     
                   }
                  myfile6.close();
                      }
               else cout << "Unable to open file"; 
  


cout << body() << html();


        system("rm output.txt");
        system("rm wynik.txt");


    }
    catch( exception & e )
    {
        cout << "Blad!!: " << e.what() << endl;
    }
   
    return 0;
}
