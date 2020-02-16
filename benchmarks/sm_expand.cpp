#include <iostream>
#include <chrono>

#include <symengine/basic.h>
#include <symengine/add.h>
#include <symengine/symbol.h>
#include <symengine/dict.h>
#include <symengine/integer.h>
#include <symengine/mul.h>
#include <symengine/pow.h>

using SymEngine::Basic;
using SymEngine::Add;
using SymEngine::Mul;
using SymEngine::Pow;
using SymEngine::Symbol;
using SymEngine::symbol;
using SymEngine::umap_basic_num;
using SymEngine::Integer;
using SymEngine::integer;
using SymEngine::multinomial_coefficients;
using SymEngine::RCP;
using SymEngine::rcp_dynamic_cast;

// Phos Smashlet 2019-09-14
#include <ctype.h>          // toupper, isprint
#include <math.h>           // sqrtf, powf, cosf, sinf, floorf, ceilf
#include <stdio.h>          // vsnprintf, sscanf, printf
#include <stdlib.h>         // NULL, malloc, free, atoi
#include <string.h>

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

namespace SymEngine
{
  int expand1(int argc, char *argv[]);
}

char sm_str[128]="Start";
static char str0[128] = "Hello, world!";

int sm_pchar( char *str0 );
int sm_proc( std::string str0 );

int main(int argc, char *argv[])
{
    SymEngine::print_stack_on_segfault();

    RCP<const Basic> x = symbol("p");
    RCP<const Basic> y = symbol("y");
    RCP<const Basic> z = symbol("z");
    RCP<const Basic> w = symbol("w");
    RCP<const Basic> i60 = integer(60);

    RCP<const Basic> e, r, t;
    
    RCP<const Basic> E[] = { x } ;

    t = add(E[0], y);

    t = add(t, z);
    // e = pow(add(add(add(x, y), z), w), i60);
    
    t = add(t, w);
    
    e = pow(t, i60);

    std::cout << "Expanding: " << *e << std::endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    r = expand(e);
    auto t2 = std::chrono::high_resolution_clock::now();
    // std::cout << *r << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1)
                     .count()
              << "ms" << std::endl;
    std::cout << "number of terms: "
              << rcp_dynamic_cast<const Add>(r)->get_dict().size() << std::endl;
              
               std::string command;
    for (int i = 1; i<argc; i++) {
        command += argv[i]; 
        if (i != argc-1) //this check prevents adding a space after last argument.
        command += " ";
    }

          
              sm_pchar("x sym: y sym: add: 2 pow: 3 5 +");
          
              sm_proc( command );
    

    return 0;
}

int sm_proc( std::string str0 )
{

    std::stack<SymEngine::RCP<const Basic>> RCP_S;
    
    // Use string stack for input and output?
    // use separate RCP stack for internal processing?
    // different type different stack, one stack for each type?
    
    // printf("\nsm_proc: %s\n", str0);
    std::cout << "\nsm_proc:   " << str0 << std::endl;

    
    int clicked=1;

            if (clicked & 1)
            {
                clicked++; // enter block only once until button is clicked again.
                // ImGui::SameLine();
                // ImGui::Text("Thanks for clicking me!");
                
                  char *pch; int tok_i=0; 
                  char tok_str[128];
                  char *SE_argv[1];
                  SE_argv[0]="0";
                  
                  // std::stack<std::string> mystack;
                  std::stack<std::string> sm_S;
                  
                  /*
                  strcpy(tok_str, str0);
                  
                  // printf ("Splitting string \"%s\" into tokens:\n",str);
                  pch = strtok (tok_str," ");
                  sprintf(sm_str, "%d %s", clicked, pch);
                  
                  if (1) while (pch != NULL)
                  {
                    // printf ("%s\n",pch);
                    pch = strtok (NULL, " ");
                    tok_i++;
                    
                    sprintf(sm_str, "%s %d %s", sm_str, tok_i, pch);
                  }
                  
                  // sprintf(sm_str, "%s %s", sm_str, str0);
                  // sprintf(sm_str, "%d", clicked);
                  // sprintf(sm_str, "%d %s", clicked, pch);
                  sprintf(sm_str, "%d %s", clicked, sm_str);
                  
                  strcpy(tok_str, str0);
                  
                  // printf ("Splitting string \"%s\" into tokens:\n",str);
                  pch = strtok (tok_str," ");
                  sprintf(sm_str, "%d %s", clicked, pch);
                  
                  if (1) while (pch != NULL)
                  {
                    // printf ("%s\n",pch);
                    pch = strtok (NULL, " ");
                    tok_i++;
                    
                    sprintf(sm_str, "%s %d %s", sm_str, tok_i, pch);
                  }
                  
                  // sprintf(sm_str, "%s %s", sm_str, str0);
                  // sprintf(sm_str, "%d", clicked);
                  // sprintf(sm_str, "%d %s", clicked, pch);
                  sprintf(sm_str, "%d %s", clicked, sm_str);
                  */
                  
                    std::string myText("some-text-to-tokenize");
                    std::istringstream iss(myText);
                    std::string token;
                    if (0) while (std::getline(iss, token, '-'))
                    {
                        std::cout << token << std::endl;
                    }
                    
                        double d0, d1, d2;
                        std::ostringstream strs;
                        std::string str;
                        
                        // std::istringstream iss_log(utf8_text);
                        
                        
                        // Phos Smashlet begins 2019-09-14
                        
                        std::istringstream iss_log(str0);
                        while (std::getline(iss_log, token, ' '))
                        {
                            // std::cout << token << std::endl;
                            
                            if (token.compare("+") == 0) {
                                // https://stackoverflow.com/questions/4754011/c-string-to-double-conversion
                                d1 = stod(sm_S.top()); sm_S.pop();
                                d2 = stod(sm_S.top()); sm_S.pop();
                                d0 = d1 + d2;
                                
                                // strs = "";
                                std::ostringstream strs;
                                strs << d0;
                                str = strs.str();

                              std::cout << "+: " << d0 <<" "<< d1 <<" "<< d2 <<" "<< str << std::endl;

                                // mystack.push("is plus");
                                sm_S.push( str );
                            }
                            else if (token.compare("ext:") == 0) { // SymEngine::expand1 terms
                            
                                // SE_argv[0]=mystack.top(); mystack.pop();
                                // sprintf(SE_argv[0], "%s", mystack.top().c_str() );
                                
                                int SE_n = 999; // SymEngine::expand1(stoi(mystack.top()), SE_argv);
                                sm_S.pop();
                                
                                // int SE_n = atoi(SE_argv[0]);
                                strs << SE_n;
                                str = strs.str();
                                sm_S.push( str );
                            }
                            else if (token.compare("sym:") == 0) { // SymEngine::expand1 terms

                              sprintf(sm_str, "%s", sm_S.top().c_str() );
                              printf("sym: TOS %s\n", sm_str);
                              
                              RCP_S.push( symbol( sm_str ) );

                              RCP<const Basic> e, r, t;
                              
                              e = RCP_S.top();
                              
                              std::cout << "Expanding: " << *e << std::endl;
                              
                              sm_S.pop();

                            }
                            else if (token.compare("add:") == 0) { // SymEngine::expand1 terms
                              RCP<const Basic> e, r, t, a, b;
                              
                              b = RCP_S.top(); RCP_S.pop();
                              a = RCP_S.top(); RCP_S.pop();
                              
                              e = add(a , b);
                              
                              std::cout << "In add: Expanding: " << *e << std::endl;

                              RCP_S.push( e );

                            }
                            else if (token.compare("pow:") == 0) { // SymEngine::expand1 terms


                              std::cout << "In pow: "  << std::endl;                              

                              RCP<const Basic> e, r, t, a;
                                                            
                              int b = stoi(sm_S.top()); sm_S.pop();
                              // std::cout << "Expanding b: " << b << std::endl;                            
                                              
                              RCP<const Basic> n = integer( b );
//                              std::cout << "Expanding b: " << b << std::endl;                            
//                              std::cout << "Expanding n: " << *n << std::endl;                              

                              a = RCP_S.top(); RCP_S.pop();

                              std::cout << "Expanding a: " << *a << std::endl;
                              
                              e = pow(a , n);
                              
                              std::cout << "Expanding: " << *e << std::endl;

                              RCP_S.push( e );

    auto t1 = std::chrono::high_resolution_clock::now();
    r = expand(e);
    auto t2 = std::chrono::high_resolution_clock::now();
    // std::cout << *r << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1)
                     .count()
              << "ms" << std::endl;
    std::cout << "number of terms: "
              << rcp_dynamic_cast<const Add>(r)->get_dict().size() << std::endl;

                              std::cout << "Expanding r: " << *r << std::endl;


                            }
                            else
                                sm_S.push(token);
                        }

                  // sprintf(sm_str, "%s mystack %s", sm_str, mystack.top().c_str() );

                  // sprintf(sm_str, "%s", mystack.top().c_str() );
                  // printf("TOS %s\n", sm_str);
    
                  if (sm_S.size()>0)                
                      std::cout << "sm_S TOS: " << sm_S.top() << std::endl;

                // ImGui::Text(str0);
                // ImGui::Text(sm_str);
            }
            else {
                // ImGui::SameLine(); ImGui::Text(sm_str);
            }

    return 0;

}


int sm_pchar( char *str0 )
{

    std::stack<SymEngine::RCP<const Basic>> RCP_S;
    
    // Use string stack for input and output?
    // use separate RCP stack for internal processing?
    // different type different stack, one stack for each type?
    
    printf("\nsm_proc: %s\n", str0);
    
    
    int clicked=1;

            if (clicked & 1)
            {
                clicked++; // enter block only once until button is clicked again.
                // ImGui::SameLine();
                // ImGui::Text("Thanks for clicking me!");
                
                  char *pch; int tok_i=0; 
                  char tok_str[128];
                  char *SE_argv[1];
                  SE_argv[0]="0";
                  
                  std::stack<std::string> mystack;
                  
                  strcpy(tok_str, str0);
                  
                  // printf ("Splitting string \"%s\" into tokens:\n",str);
                  pch = strtok (tok_str," ");
                  sprintf(sm_str, "%d %s", clicked, pch);
                  
                  if (1) while (pch != NULL)
                  {
                    // printf ("%s\n",pch);
                    pch = strtok (NULL, " ");
                    tok_i++;
                    
                    sprintf(sm_str, "%s %d %s", sm_str, tok_i, pch);
                  }
                  
                  // sprintf(sm_str, "%s %s", sm_str, str0);
                  // sprintf(sm_str, "%d", clicked);
                  // sprintf(sm_str, "%d %s", clicked, pch);
                  sprintf(sm_str, "%d %s", clicked, sm_str);
                  
                  strcpy(tok_str, str0);
                  
                  // printf ("Splitting string \"%s\" into tokens:\n",str);
                  pch = strtok (tok_str," ");
                  sprintf(sm_str, "%d %s", clicked, pch);
                  
                  if (1) while (pch != NULL)
                  {
                    // printf ("%s\n",pch);
                    pch = strtok (NULL, " ");
                    tok_i++;
                    
                    sprintf(sm_str, "%s %d %s", sm_str, tok_i, pch);
                  }
                  
                  // sprintf(sm_str, "%s %s", sm_str, str0);
                  // sprintf(sm_str, "%d", clicked);
                  // sprintf(sm_str, "%d %s", clicked, pch);
                  sprintf(sm_str, "%d %s", clicked, sm_str);
                  
                    std::string myText("some-text-to-tokenize");
                    std::istringstream iss(myText);
                    std::string token;
                    if (0) while (std::getline(iss, token, '-'))
                    {
                        std::cout << token << std::endl;
                    }
                    
                        double d0, d1, d2;
                        std::ostringstream strs;
                        std::string str;
                        
                        // std::istringstream iss_log(utf8_text);
                        
                        
                        // Phos Smashlet begins 2019-09-14
                        
                        std::istringstream iss_log(str0);
                        while (std::getline(iss_log, token, ' '))
                        {
                            // std::cout << token << std::endl;
                            
                            if (token.compare("+") == 0) {
                                // https://stackoverflow.com/questions/4754011/c-string-to-double-conversion
                                d1 = stod(mystack.top()); mystack.pop();
                                d2 = stod(mystack.top()); mystack.pop();
                                d0 = d1 + d2;
                                strs << d0;
                                str = strs.str();

                                // mystack.push("is plus");
                                mystack.push( str );
                            }
                            else if (token.compare("ext:") == 0) { // SymEngine::expand1 terms
                            
                                // SE_argv[0]=mystack.top(); mystack.pop();
                                // sprintf(SE_argv[0], "%s", mystack.top().c_str() );
                                
                                int SE_n = 999; // SymEngine::expand1(stoi(mystack.top()), SE_argv);
                                mystack.pop();
                                
                                // int SE_n = atoi(SE_argv[0]);
                                strs << SE_n;
                                str = strs.str();
                                mystack.push( str );
                            }
                            else if (token.compare("sym:") == 0) { // SymEngine::expand1 terms

                              sprintf(sm_str, "%s", mystack.top().c_str() );
                              printf("sym: TOS %s\n", sm_str);
                              
                              RCP_S.push( symbol( sm_str ) );

                              RCP<const Basic> e, r, t;
                              
                              e = RCP_S.top();
                              
                              std::cout << "Expanding: " << *e << std::endl;

                            }
                            else if (token.compare("add:") == 0) { // SymEngine::expand1 terms
                              RCP<const Basic> e, r, t, a, b;
                              
                              b = RCP_S.top(); RCP_S.pop();
                              a = RCP_S.top(); RCP_S.pop();
                              
                              e = add(a , b);
                              
                              std::cout << "In add: Expanding: " << *e << std::endl;

                              RCP_S.push( e );

                            }
                            else if (token.compare("pow:") == 0) { // SymEngine::expand1 terms


                              std::cout << "In pow: "  << std::endl;                              

                              RCP<const Basic> e, r, t, a;
                                                            
                              int b = stoi(mystack.top()); mystack.pop();
                              // std::cout << "Expanding b: " << b << std::endl;                            
                                              
                              RCP<const Basic> n = integer( b );
//                              std::cout << "Expanding b: " << b << std::endl;                            
//                              std::cout << "Expanding n: " << *n << std::endl;                              

                              a = RCP_S.top(); RCP_S.pop();

                              std::cout << "Expanding a: " << *a << std::endl;
                              
                              e = pow(a , n);
                              
                              std::cout << "Expanding: " << *e << std::endl;

                              RCP_S.push( e );

    auto t1 = std::chrono::high_resolution_clock::now();
    r = expand(e);
    auto t2 = std::chrono::high_resolution_clock::now();
    // std::cout << *r << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1)
                     .count()
              << "ms" << std::endl;
    std::cout << "number of terms: "
              << rcp_dynamic_cast<const Add>(r)->get_dict().size() << std::endl;

                              std::cout << "Expanding r: " << *r << std::endl;


                            }
                            else
                                mystack.push(token);
                        }

                  // sprintf(sm_str, "%s mystack %s", sm_str, mystack.top().c_str() );

                  sprintf(sm_str, "%s", mystack.top().c_str() );
                  printf("TOS %s\n", sm_str);

                // ImGui::Text(str0);
                // ImGui::Text(sm_str);
            }
            else {
                // ImGui::SameLine(); ImGui::Text(sm_str);
            }

    return 0;

}
