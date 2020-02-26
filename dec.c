  char ch;

  int j, key;

  char str_message[] = "Verhsq jyr Aegxw"; 

  key = 4;

  for(j = 0; str_message[j] != '\0'; ++j){

    ch = str_message[j];

    if(ch >= 'a' && ch <= 'z'){

      ch = ch - key;

      if(ch < 'a'){

        ch = ch + 'z' - 'a' + 1;

      }

      str_message[j] = ch;

    }

    else if(ch >= 'A' && ch <= 'Z'){

      ch = ch - key;

      if(ch < 'A'){

        ch = ch + 'Z' - 'A' + 1;

      }

      str_message[j] = ch;

    }

  }