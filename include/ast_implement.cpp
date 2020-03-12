#include "menu.hpp"

void abstract_declarator::translate(string& pyout)const{
    debug(cname);
    NotImplemented();
}

void argument_expression_list::translate(string& pyout)const{
    debug(cname);
    NotImplemented();
}

void assignment_expression::translate(string& pyout)const{
  debug(cname);
  string one;
  string five;
  p_one->translate(one);
  p_five->translate(five);

  switch (type)
  {
    case 0:
    pyout = one + "=" + five;
    break;

    case 1:
    pyout = one + "*=" + five;
    break;

    case 2:
    pyout = one + "/=" + five;
    break;

    case 3:
    pyout = one + "%=" + five;
    break;

    case 4:
    pyout = one + "+=" + five;
    break;

    case 5:
    pyout = one + "-=" + five;
    break;

    case 6:
    pyout = one + "<<=" + five;
    break;

    case 7:
    pyout = one + ">>=" + five;
    break;

    case 8:
    pyout = one + "&=" + five;
    break;

    case 9:
    pyout = one + "^=" + five;
    break;

    case 10:
    pyout = one + "|=" + five;
    break;
  }
}

void base_expression::translate(string& pyout)const{
  debug(cname);
  string one;
  string five;
  p_one->translate(one);
  p_five->translate(five);
  pyout = one + "," + five;
}

void cast_expression::translate(string& pyout) const{
      debug(cname);
  std::string op;
  switch (type)
  {
    case 0:
    ptr->translate(pyout);
    opt->translate(op);
    pyout = pyout + "(" + op + ")";
    break;

    default:
    NotImplemented();
  }
}

void compound_statement::translate(string& pyout) const{
  debug(cname);
  string ds, ss;
  switch (type) {
    case 0:
    break;//do nothing?
    case 1:
    //indentation++; //encounter "{"
    left->translate(pyout);
    //indentation--; //exit with "}"
    break;
    case 2:
    // indentation++; //encounter "{"
    left->translate(pyout);
    // indentation--; //exit with "}"
    break;
    case 3:
     //indentation++;
    left->translate(ds);
    right->translate(ss);
     //indentation--;
    pyout = ds + '\n' + ss;
    break;

  }
}

void conditional_expression::translate(string& pyout) const{
  debug(cname);
  NotImplemented();
}

void declaration_list::translate(string& pyout)const{
 debug(cname);
 string l;
 string r;

 p_o->translate(l);
 p_t->translate(r);
 pyout = l + "\n" + r;
}

void declaration_specifiers::translate(string& pyout)const{
  debug(cname);

  //for struct, skip for translation
  //translation would not be requied here
}

void declaration::translate(string& pyout) const
{
  string s_spec, s_list;
  debug(cname);
  if(lt == NULL)
  {
    spec -> translate(pyout);
  }
  else{
    //omit declaration specifier(int, double) for python translation
    spec-> translate(s_spec);
    lt-> translate(s_list);
    pyout = s_spec + s_list;
  }
  global_variables.push_back(pyout);
}



void declarator :: translate(string& pyout) const{
  debug(cname);
  //std::cout << "declarator translate" << '\n';
  //skip for translation
}

void direct_abstract_declarator::translate(string& pyout) const{
  debug(cname);
  NotImplemented();
}

void direct_declarator::translate(string& pyout) const{
  debug(cname);
  string ls, rs;
  switch (type) {
    case 0:
    pyout = id; // directly output IDENTIFIER, as python doesn't have type
    break;
    case 1:
    one->translate(pyout); // parenthsis does not matter in IDENTIFIER
    break;
    case 2:
    NotImplemented(); // no array
    break;
    case 3:
    NotImplemented();
    break;
    case 4:
    one -> translate(ls);
    two -> translate(rs);
    pyout = ls + "(" + rs + ")" ;//+ '\n';
    break;
    case 5:
    one -> translate(ls);
    two -> translate(rs);
    pyout = ls + "(" + rs + ")" ;//+ '\n';
    break;
    case 6:
    one -> translate(ls);
    pyout = ls + "("  + ")";// + '\n';
    break;
  }
}

void expression_statement::translate(string& pyout) const{
  debug(cname);
  //string tmp;
  if(ptr_expr != NULL)
  {
    ptr_expr -> translate(pyout);
  }
  //if it is " ; ",we don't do anything, skip(not sure)
  // ";"suggest a null statement, do nothing
}

void function_definition::translate(string& pyout) const{
 debug(cname);
 string specify;
 string declarator;
 string statement;
 string global;

 p_t->translate(declarator);
 p_f->translate(statement);
 for (int i = 0; i < global_variables.size(); i++)
 {
   global = global + "global " + global_variables[i] + "\n";
 }
 pyout = "def " + declarator + ":\n" + global + statement + "\n";//喵喵喵
}


void identifier_list::translate(string& pyout) const{
  debug(cname);
    NotImplemented();
  }

  void init_declarator_list::translate(string& pyout) const{
    debug(cname);
    string s1, s2;
    one-> translate(s1);
    two -> translate(s2);
    pyout = s1 + '\n' + s2 + '\n';
  }


  void init_declarator::translate(string& pyout) const{
    debug(cname);
    string s1, s2;
    one-> translate(s1);
    std::cerr << "s1 " <<s1 <<'\n';
    two -> translate(s2);
    std::cerr << "s2 " <<s2 <<'\n';
    pyout = s1 + '=' + s2 + '\n';
    std::cerr << "current pyout in init_declarator is " << pyout <<'\n';
  }

  void initializer_list::translate(string& pyout) const{
    debug(cname);
    string l;
    string r;
    left->translate(l);
    right->translate(r);

    switch(type)
    {
      case 0:
      pyout = l;
      break;

      case 1:
      NotImplemented();
      break;
    }
  }

  void initializer::translate(string& pyout) const{
      debug(cname);
      NotImplemented();
    }

    void iteration_statement::translate(string& pyout)const{
    	debug(cname);
    	string ones, twos, threes, fours;
    	switch (type) {
    		case 0:
    		yi -> translate(ones);
    		er -> translate(twos);
    		pyout = "while (" + ones + "):" + '\n' + indent(twos) + '\n';
    		break;
    		default:
    		NotImplemented();
    		break;
    	}

    }

    void jump_statement::translate(string& pyout) const
    {
      debug(cname);
      string return_expression;
      switch (type) {
        case 4 ://return
        expre_ptr -> translate(return_expression);
        pyout = "return " + return_expression + "\n";
        break;

        default :
        NotImplemented();
      }
    }

    void labeled_statement::translate(string& pyout) const{
      debug(cname);
      NotImplemented();
    }


    void multiplicative_expression::translate(string& pyout) const
    {
      debug(cname);
      string ls, rs;
      mul -> translate(ls);
      cast -> translate(rs);
      switch(type){
        // case 0:
        // cast->translate(pyout);
        // break;

        case 1:
        pyout = ls + "*" + rs + "\n";
        break;

        case 2:
        pyout = ls + "/" + rs + "\n";
        break;

        case 3:
        pyout = ls + "%" + rs + "\n";
        break;

      }
    }

    void additive_expression::translate(string& pyout) const
    {
      debug(cname);
      string ls, rs;
      add -> translate(ls);
      mul -> translate(rs);
      switch(type){
        // case 0:
        // mul->translate(pyout);
        // break;

        case 1:
        pyout = ls + "+" + rs+"\n";
        break;

        case 2:
        pyout = ls + "_" + rs+"\n";
        break;
      }
    }

    void shift_expression::translate(string& pyout) const
    {
      debug(cname);
      string ls, rs;
      l -> translate(ls);
      r -> translate(rs);
      switch(type){
        // case 0:
        // mul->translate(pyout);
        // break;

        case 1:
        pyout = ls + "<<" + rs+"\n";
        break;

        case 2:
        pyout = ls + ">>" + rs+"\n";
        break;
      }
    }


    void parameter_declaration::translate(string& pyout) const{
      debug(cname);
      string yi;
      string er;
      left -> translate(yi);
      right -> translate(er);
      switch(type)
      {
        case 0:
        pyout = er;

        case 1:
        NotImplemented();

        case 2:
        NotImplemented();
      }
    }

    void parameter_list::translate(string& pyout) const{
      debug(cname);
      string yi;
      string er;
      left -> translate(yi);
      right -> translate(er);
      pyout = yi + "," + er;
    }

    void pointer::translate(string& pyout) const{
      debug(cname);
      NotImplemented();
    }

    void postfix_expression::translate(string& pyout) const{
      debug(cname);
    std::string op;
    switch (type)
    {
      case 0:
      ptr->translate(pyout);
      pyout = pyout + "()";
      break;

      case 1:
      ptr->translate(pyout);
      pyout = pyout + "()";
      break;

      case 2:
      ptr->translate(pyout);
      opt->translate(op);
      pyout = pyout + "(" + op + ")";
      break;

      case 3:
      ptr->translate(pyout);
      opt->translate(op);
      pyout = pyout + "." + op;
      break;

      // case 4:
      // ptr->translate(pyout);
      // pyout = pyout + "->7" + element;
      // break;


      case 5:
      ptr->translate(pyout);
      pyout = pyout + "+=1";
      break;

      case 6:
      ptr->translate(pyout);
      pyout = pyout + "-=1";
      break;

      default:
      NotImplemented();
     }
    }

    void primary_expression::translate(string& pyout) const
    {
      debug(cname);
      switch(type){
        case 0:
          pyout = element;
          break;

        case 1://constant representation in c different from python
          pyout = element;
          break;

        case 2:
          pyout = element;
          break;

        case 3:
          expre_ptr->translate(pyout);//for "(" expression ")"
          break;
      }
    }

    void relational_expression::translate(string& pyout) const{
    debug(cname);
    std::string op;
    ptr->translate(pyout);
    opt->translate(op);
    switch (type)
    {
      case 0:
      pyout = pyout + "<" + op;
      break;

      case 1:
      pyout = pyout + ">" + op;
      break;

      case 2:
      pyout = pyout + "<=" + op;
      break;

      case 3:
      pyout = pyout + ">=" + op;
      break;

      case 4:
      pyout = pyout + "==" + op;
      break;

      case 5:
      pyout = pyout + "!=" + op;
      break;

      case 6:
      pyout = pyout + "&" + op;
      break;

      case 7:
      pyout = pyout + "^" + op;
      break;

      case 8:
      pyout = pyout + "|" + op;
      break;

      case 9:
      pyout = pyout + "and" + op;
      break;

      case 10:
      pyout = pyout + "or" + op;
      break;


      default:
      NotImplemented();
      }
    }

    void selection_statement::translate(string& pyout) const
    {
      debug(cname);
      string expres, ifs,elses;
      expre_ptr -> translate(expres);
      ifsta -> translate(ifs);
      switch (type) {
        case 0:
        indentation++;
        pyout = "if (" + expres + "):" + '\n' + indent(ifs) ;
        break;
        case 1:
        elsesta->translate(elses);
        pyout = "if (" + expres + "):" + '\n' + indent(ifs) + "else:" + '\n'+ indent(elses) + '\n';
        break;
        case 2: //no required to translate switch
        NotImplemented();
        break;
      }
    }

    void specifier_qualifier_list::translate(string& pyout) const
    {
      debug(cname);
      //skip, no type for python
    }

    void statement_list::translate(string& pyout) const
    {
      debug(cname);
      string ls, rs;
      l -> translate(ls);
      r -> translate(rs);
      pyout = ls +'\n' + rs + '\n';
    }

    void storage_class_specifier::translate(string& pyout) const{
      debug(cname);
      NotImplemented(); // e.g typedef, so on... not in python
    }

    void translation_unit::translate(string& pyout) const{
      debug(cname);
      std::cout << "In translation unit->translate " << std::endl;
      string unit;
      string declaration;
      std::cout << "inside translation unit" << '\n';
      p_yi->translate(unit);
      p_er->translate(declaration);

      pyout = unit + "\n" + declaration;
    }

    void type_name::translate(string& pyout) const{
        debug(cname);
        NotImplemented();
      }

    void type_specifier::translate(string& pyout) const
    {
      debug(cname);
        //std::cout << "here is the type specifier. pyout is : "  << pyout << std::endl;
        //skip, no type for python
    }

    void unary_expression::translate(string& pyout) const{
      debug(cname);
      switch (type)
      {
        case 0:
        ptr->translate(pyout);
        pyout = pyout + "+=1";
        break;

        case 1:
        ptr->translate(pyout);
        pyout = pyout + "-=1";
        break;

        // case "&":
        // ptr->translate(pyout);
        // pyout = "&" + pyout;
        // break;

        case 5:
        ptr->translate(pyout);
        pyout = "*" + pyout;
        break;

        case 6:
        ptr->translate(pyout);
        pyout = "+" + pyout;
        break;

        case 7:
        ptr->translate(pyout);
        pyout = "-" + pyout;
        break;

        // case "~":
        // ptr->translate(pyout);
        // pyout = "~" + pyout;
        // break;
        //
        // case "!":
        // ptr->translate(pyout);
        // pyout = "!" + pyout;
        // break;

        case 2:
        ptr->translate(pyout);
        pyout = "sys.getsizeof(" + pyout + ")";
        break;

        case 3:
        ptr->translate(pyout);
        pyout = "sys.getsizeof(" + pyout + ")";
        break;

        default:
        NotImplemented();
      }
    }
