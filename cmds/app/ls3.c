// ls.c
// creator:     Fan@falling-sun.chinesemud.net
// creat time:  1999/04/05


#include "/doc/help.h"
#include <localtime.h>

inherit F_CLEAN_UP;
#define L_LINE sprintf("%-30s%8s  %s", "����޸�ʱ��", "�ߴ�", "�ļ���")
#define DASHES "-----------------------------------------------------------------"
#define F_FLAG  1
#define S_FLAG  2
#define L_FLAG  4
#define A_FLAG  8
#define T_FLAG  16
#define R_FLAG  32
#define X_FLAG  64
#define ONE_FLAG 128
#define CAP_A_FLAG 256

private mixed   internal_ls(string path, int active, int internal_call);
mixed           map_junk(mixed junk, int index);
int             sort_by_time(mixed a, mixed b);
int             sort_by_ext(mixed a, mixed b);
int             filter_directories(mixed junk);
int             filter_no_period(mixed junk);
int      filter_valid_directories(mixed junk);
nosave string pathname;

int main(object me, string arg)
{
    int         i;
    int         active;
    string      flags,str;
    string  *output;
    
    seteuid(geteuid(me));

    if (!arg)  arg = "";
    else    arg += " ";

    while (sscanf(arg, "-%s %s", flags, str) > 1
    || sscanf(arg, "%s -%s", str,flags) > 1 ) {
      arg=str;
           i = strlen(flags);
           while (i--)
              switch (flags[i]) {
                 case 'F':   active |= F_FLAG;    break;
                 case 's':      active |= S_FLAG;               break;
                 case 'l':      active |= L_FLAG;               break;
                 case 'a':      active |= A_FLAG;               break;
                 case 't':      active |= T_FLAG;               break;
                 case 'r':      active |= R_FLAG;               break;
                 case 'x':      active |= X_FLAG;               break;
                 case '1':      active |= ONE_FLAG;     break;
                 case 'A':      active |= CAP_A_FLAG;   break;
              }
    }
    if (arg[<1..<1] == " ")   arg = arg[0..<2];
    if (arg == "/..") {
           write("ls: û��������Ŀ¼��\n");
           return 1;
    }
//  '-l'��'-s'�ǲ��ܼ��ݵĲ���
    if (active & L_FLAG) active &= ~S_FLAG;

    arg = resolve_path(me->query("cwd"), arg);

//  ��ֹ�ڸ�Ŀ¼ʹ��'-r' ����    
    output=explode(arg,"/");
    if (!sizeof(output) && R_FLAG)
        active &=~R_FLAG;

    if (output = internal_ls(arg, active, 0)) {
           me->start_more(sprintf("\n%s\n",implode(output,"\n")));
    }
    return 1;
}
//  �����ļ����ڵ�Ŀ¼

protected string get_path(string str)
{
    mixed *tmp;
    string path;

    if(str == "/")       return "/";

    if(str[strlen(str)-1] == '/')   return str;
    else if(file_size(str)==-2)  return str+"/";
 
    tmp = explode(str, "/") - ({ 0 });
    if (sizeof(tmp)>=2)
        path = "/" + implode( tmp[0..sizeof(tmp)-2], "/")+"/";
    else
        path="/";
    if(path == "//")  path = "/";
 
    return path; 
}

private mixed internal_ls(string arg, int active, int internal_call)
{
    mixed   *junk,*local;
    string  *files;
    int     *times;
    int     *sizes;
    string  *dirs;
    int         first_period;
    int   i;
    string  *output;
    mixed       tmp;
    string      path,file_time;

    pathname=get_path(arg);

    output = ({ sprintf("Ŀ¼: [%s]", pathname) });

    if (internal_call) {
              path = arg;
              arg += "*";
    } else {
              if (arg[<1..< 1] != "/" && file_size(arg + "/") == -2)
                 arg += "/";
              path = arg;
              if (arg[<1..<1] == "/") {
                 arg += "*";
              } else {
                 for (i = strlen(path); path[--i] != '/';);
                 first_period = path[i+1] == '.';
                 path = path[0..i];
              }
    }

    junk = get_dir(arg, -1);
    if (!sizeof(junk)) {
              write("ls: "+arg+" û���������ļ�����Ŀ¼��\n");
              return 0;
    }
   junk=filter_array(junk,"filter_valid_directories",this_object());

    if (!(active & A_FLAG) && !first_period) {
           junk = filter_array(junk, (active & CAP_A_FLAG)?"filter_limit_period":
                            "filter_no_period", this_object());
           if (!sizeof(junk)) {
              if (internal_call)
                return ({ sprintf("%s: Ŀ¼�ǿյġ�", path) });
              write(pathname+" Ŀ¼�ǿյġ�\n");
              return 0;
           }
    }

    if (active & T_FLAG)
           junk = sort_array(junk, "sort_by_time", this_object());

    if (active & X_FLAG)
           junk = sort_array(junk, "sort_by_ext", this_object());

    if (active & R_FLAG)
           dirs = map_array(
                filter_array(junk, "filter_directories", this_object()),
                "map_junk", this_object(), 0);

    files = map_array(junk, "map_junk", this_object(), 0);
    sizes = map_array(junk, "map_junk", this_object(), 1);
    times = map_array(junk, "map_junk", this_object(), 2);

    if (active & (F_FLAG | S_FLAG)) {
           for (i = sizeof(sizes); i--;) {
              if (active & S_FLAG) {
                      tmp = (sizes[i] >= 0) ?
                      sprintf("%3d %s", (sizes[i] + 1023) / 1024, files[i]) :
                      sprintf("  - %s", files[i]);
              } else {
                      tmp = files[i];
              }
              if (active & F_FLAG) {
                      if (sizes[i] == -2) {
                         tmp += "/";
                      } else if (files[i][<2..<1] == ".c" &&
                              find_object(path + files[i])) {
                            tmp += "*";
                         }
              }
              files[i] = tmp;
           }
    }

    if (active & L_FLAG) {
           int out_idx, max;

           out_idx = sizeof(output += ({L_LINE,DASHES}));
           output += allocate(max = sizeof(files)+1);

           for (i = 0; i < max-1; i++) {
              local=localtime(times[i]);
              file_time=sprintf("%4d��%2d��%2d��%2dʱ%2d��%2d��",local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],local[LT_HOUR],local[LT_MIN]+1,local[LT_SEC]+1);
              output[out_idx++] = (sizes[i] >= 0) ?
                   sprintf("%-30s %8d %s", file_time, sizes[i], files[i]) :
                   sprintf("%-30s %8s %s", file_time, "<DIR>", files[i]);
           }
           output += ({DASHES});
    } else if (!(active & ONE_FLAG) ) {
                 for (i = 0; i < sizeof(files); i += 300) {
                    output += explode(sprintf("%-79#s\n", implode(files[i..(i + 299)],
                                                          "\n")), "\n");
                 }  
      } else {
              output += files;
      }

    if (active & R_FLAG) {
         reset_eval_cost();
              for (i = 0; i < sizeof(dirs); i++)
              output += ({ "" }) + internal_ls(path + dirs[i] + "/", active, 1);
    }
    return output;
}

mixed map_junk(mixed junk, int index)
{
    return junk[index];
}

int filter_no_period(mixed junk)
{
    if (junk[0][0] != '.') return 1;
}

int filter_limit_period(mixed junk)
{
    if (junk[0] != "." && junk[0] != "..") return 1;
}


int filter_directories(mixed junk)
{
    if (junk[1] == -2 && junk[0] != "." && junk[0] != "..")
        return 1;
}

int sort_by_time(mixed file_a, mixed file_b)
{
    return file_a[2] > file_b[2] ? 1 : -1;
}

int sort_by_ext(mixed file_a, mixed file_b)
{
    file_a = " ." + file_a[0];
    file_b = " ." + file_b[0];
    file_a = explode(file_a, ".");
    file_b = explode(file_b, ".");
    if (sizeof(file_a) == 2 || sizeof(file_b) == 2)
        return sizeof(file_a) > sizeof(file_b) ? 1 : -1;
    return file_a[sizeof(file_a) - 1] > file_b[sizeof(file_b) - 1] ? 1 : -1;
}

int filter_valid_directories(mixed junk)
{
   if (junk[0] == "." || junk[0] == "..") return 1;
   if (file_size(pathname+junk[0]) == -1)
      return 0;
   else
           return 1;
        
}

int help(object me)
{
    write(@HELP
ָ���ʽ: ls [ -aslFrtx1 ] [<·����>]
 
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г�����Ŀ¼
�����ݣ����г��ĵ����к����ʾ * �ŵ����Ѿ�����������
 
��:
'ls /' ���г�����λ�ڸ�Ŀ¼�µĵ�������Ŀ¼.
  ������
        -a  �г�����ָ��Ŀ¼�µ��ļ�������'.'��'..'
        -A  �����ڲ���-a�����˲���ʾ'.' �� '..'
        -s  ���ļ�ǰ��KilloBytes�Ľ���ֵ��ʾ�ļ���С
        -F  ��Ŀ¼������ '/' ��ʾһ��Ŀ¼����'*' ��ʾһ���Ѿ�������ļ�
        -l  ����ϸ�ĸ�ʽ��ʾ
        -r  �ݹ���ʾָ��Ŀ¼�µ��ļ�����Ŀ¼�µ��ļ�
        -t  ��ʱ��˳������
        -x  ���ļ�����չ������
        -1  ��һ��һ���ļ��ĸ�ʽ��ʾ
        ��֧�ֵĲ����������ԡ�
        �����ͨ��alias �趨�Լ�ϲ���Ĳ������磺 alias ls ls -F $*
 
HELP
    );
    return 1;
}

