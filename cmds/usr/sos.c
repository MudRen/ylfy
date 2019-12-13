// sos.c
 
#include <ansi.h>
#include <command.h>
 
inherit F_CLEAN_UP;

#define BOARD get_object("/clone/board/bugs_b")
#define LOOK_CMD "/cmds/std/look"
 
int help(object me);

int main(object me, string arg)
{
        string arg2;
        
        if (! arg)
        {
                return help(me);
        }
        
        if (arg == "list")
        {
                LOOK_CMD->look_item(me, BOARD);
                return 1;
        } 
        
        if (sscanf(arg, "%s %s", arg, arg2) == 2) 
        {
                switch (arg) {
                case "post":
                        BOARD->do_post(arg2);
                        break;
                case "read":
                        BOARD->do_read(arg2);
                        break;
                case "re"  :
                        BOARD->do_re(arg2);
                        break;  
                case "search":
                        BOARD->do_search(arg2);
                        break; 
                default:
                        help(me);
                        break;
                        
                }
                return 1;
        } 

		return help(me);
}

int help(object me)
{
        write(@HELP
ָ���ʽ :   
           sos post <����>  ����        
           sos list         �鿴
           sos read next|new|<���ӱ��>
           sos search title|author|document
           sos re <���ӱ��>.<�ظ�����>
���ָ�������ϵͳ���ֳ���ʱ������ʦ������
���������Ӧ�ý����ֵ������ϵͳ����ʾ����
��ϸ�ؽ���˵�����Ա���ʦ�޸ĸó��档
HELP
        );

        return 1;
}

