// zhenyue.c
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
���������Ϊƽ̹���ϡ���ɽ���οͶ��ڴ�������Ϣ�ټ���ǰ�С���
���м����ª�����磬���Ƕ�����ճ��ߣ�����ͷ��ЪϢ�ڴˡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
        "westup" : __DIR__"canglong",
        "southwest" : __DIR__"chaoyang",
        "eastup" : __DIR__"yunu",
        "northdown" : __DIR__"husun",
    ]));
    set("objects", ([ 
        __DIR__"npc/gao" : 1,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "huashan" );
    setup();
}
 
int valid_leave(object me, string dir)
{
    object ob;
    ob=present("gao genming", environment(me));
    if (dir != "northdown" && objectp(ob) && living(ob) )
        if(mapp(me->query("family")) && me->query("family/family_name") !="��ɽ��")
        if(me->query("combat_exp") >= 1000)
        if( !wizardp(me) )
        return notify_fail("�߸����ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
    return ::valid_leave(me, dir);
}
