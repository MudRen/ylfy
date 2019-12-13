// Room: /d/shaolin/guangchang2.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "�㳡");
    set("long", @LONG
�����������������ƽ�е���ʯ̨������ǰ����һ�����
����̨���Ͽ̵��������ڷ�����޺��Լ���ǧ٤����������
��ƽ̨�����з�Ҳ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�����
���գ�����Ʈ�ƣ���λ������Դ����ߵ�ݡ����Ҹ�ͨ��һ��
СԺ����������������ʡ���ǰ�����Ǵ��۱��
LONG
    );
    set("exits", ([
        "south" : __DIR__"twdian",
        "north" : __DIR__"guangchang3",
        "northup" : __DIR__"dxbdian",
        "east" : __DIR__"zhonglou",
        "west" : __DIR__"gulou",
    ]));
    set("outdoors", "shaolin");
    set("objects",([
        __DIR__"npc/xiang-ke" : 1,
        __DIR__"npc/seng-bing3" : 2,
        CLASS_D("shaolin") + "/qing-shan" : 1,
    ]));
    setup();
}
void init()
{
    object me=this_player();
    object ob=present("yingxiong ling",me);
    mapping myfam;
    myfam = (mapping)me->query("family");
    if (myfam)
    if (myfam["family_name"] == "������" && me->query("gender")=="����") return;
    if (!ob)
    if (userp(me)){
            tell_object(me, HIY "����ɮ������ȵ���ʩ��δ���������룬��ν����ģ�Ī�����󱲣�\n"+"ֻ��һ�����Ƽ���㣬��������ر��ӳ��������£�\n" NOR);
            me->move("/d/nanyang/shanmen");
            message("vision",
                HIY "ֻ��ƹ��һ����������һ��������һ����\n"
                "ԭ����һ���������ļһ���������ﱻ���˳�����\n" NOR, environment(me), me);
    }
}
