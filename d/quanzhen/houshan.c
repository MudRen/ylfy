//houshan.c ��ɽ 

#include <room.h>
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
������ȫ��̵ĺ�ɽ��������ȫ������Լ�������ũ����Ÿ����߲ˡ�
������һ�����������һƬ�����֣���ǰ����һ������(paizi)��
LONG
        );
        set("outdoors", "quanzhen");

        set("exits", ([
              "east" : __DIR__"qingsonglin1",
             "southdown": __DIR__"xiaolu2" 
        ]));

         set("item_desc",([
                "paizi"        :       "\n\t\t\t  \n\n\n" 
                                          HIR"\t\t�ˡˡˡˡˡˡˡˡ�\n"
                                          "\t\t�ˡ���     ��   ��\n"
                                          "\t\t�ˡ�            ��\n"
                                          "\t\t�ˡ�ɽ     ��   ��\n"
                                          "\t\t�ˡ�            ��\n"
                                          "\t\t�ˡ���     ��   ��\n"
                                          "\t\t�ˡ�            ��\n"
                                   "\t\t�ˡ���     ��   ��\n"
                                 " \t\t�ˡˡˡˡˡˡˡˡ�\n\n\n"NOR,
                                                        
                ]));



        
        setup();
        replace_program(ROOM);
}

