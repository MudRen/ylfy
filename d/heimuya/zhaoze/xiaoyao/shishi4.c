// shishi4.c
// by shilling 97.2
inherit ROOM;
void create()
{
        set("short", "����ʯ��");
        set("long", @LONG
����һ�����µ�����ʯ�ң�������Ըо��õ���ֻ��ǿ�ҵ�ɱ�����Լ�
����ص׵�һЩ���ŵ���ζ����΢���ĵƹ��£��㾹Ȼ�����и���վ�����
�������º�����·��
LONG
        );
       set("exits", ([
               "up" : __DIR__"fangjian2",
               "down" : __DIR__"shishi5",
       ]));
    set("objects",([
        __DIR__"npc/qingyun" : 1,
    ]));
    setup();
}
int valid_leave(object me,string dir)
{
    object ob=present("qingyun",environment(me));
    if (ob && living(ob) )
        if(dir=="down" && (me->query("family/master_name")!="��ң��") ) 
             return notify_fail("����һ��������ס�����ȥ·��\n");
    return ::valid_leave(me,dir);
}

