// tianye.c
// marry 99.8
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "��Ұ");
        set("long",
"����Ƭһ���޼ʵ���Ұ�������˴���Ȼ�Ĳ���������Զ����������Ĵ�ɽʹ��\n"
"�е���Զ�붼�����Ӻ��ƽ���Ͱ�����Ψһ��Щ������ò���г�����������Ե�һ��\n"
"Ƭ���׵ء�\n\n"
);
                set("outdoors", "cxwxm");
        set("exits", ([ /* sizeof() == 2 */
         "west" : "/d/city3/shandao2",
]));

        setup();
}
void init()
{
        this_player()->set("jihao",0);
        add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{
        object me = this_player();

    if(arg)  
   {
    write("������ʲô��\n");
         return 1;
    }

    message_vision(
    "$NͷҲ���ص���������׵ء�\n", this_player());

        if ((me->query("family/family_name") == "����������"))
        {
                me->move(__DIR__"cxwx");
         }
        else
        {      
                me->move(__DIR__"yumi4");
         }
         return 1;
}

