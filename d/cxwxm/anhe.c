inherit ROOM;

#include <ansi.h>

void create()
{
        set("short","����");
        set("long","����һ�����°��ӣ��������κγ��ڣ�����ĺ�ˮ��shui)�����㷢����\n\n");
        set("item_desc", ([
                "shui" : "��Ψһ�ĳ�·ֻ��Ǳ��ˮ��ȥ���������ˡ�\n" ]) );
        setup();
}
void init()
{
        add_action("do_qian", "qian");
}
int do_qian(string arg)
{
        object me = this_player();

    if( !arg || arg!="shui" )
        {
        write("��Ҫ���Ķ���\n");
        return 1;
    }
    message_vision( "$NӲ��ͷƤ����һǱ��\n", this_player());
{               me->move(__DIR__"pubu");
                this_player()->set("qi",1);
                this_player()->unconcious();
                return 1;
}               
}
