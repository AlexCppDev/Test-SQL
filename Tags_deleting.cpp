#include "Tags_deleting.h"
#pragma once

char* Tags_deleting::str_tags_delete(char* str)
{
    char *buf = new char[strlen(str)+1]; 
    bool tag_started_flag = false; 
    int count = 0; 
    // Copy to buffer char array without tags 
    for (int i = 0; i < strlen(str)+1; i++)
    { 
       
        if (str[i] == '<')
        {
         tag_started_flag = true;
        }

        if (str[i] == '>')
        {
            tag_started_flag = false;
            continue;
        }
        
        if (!tag_started_flag)
        {
            buf[count] = str[i];
            count++;
        };
        
    }
    return buf;
}
