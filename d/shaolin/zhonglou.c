// Room: /d/shaolin/zhonglou.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "��¥СԺ");
    set("long", @LONG
����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ�����
���ᣬ�ܽ��Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ����
�յ�������������ǵ�����һ������̬άФ��������������֮
�֡�������ڴ�����һ�ȹ��ε�Сľ�ţ����������ò���Ϳ�棬
��������������ɽ�������ڷ𽲾�ʱ�����Ρ�
LONG
    );
    set("exits", ([
        "west" : __DIR__"guangchang2",
        "enter" : __DIR__"zhonglou1",
    ]));
    set("objects",([
        __DIR__"npc/seng-bing3" : 2,
    ]));
    set("outdoors", "shaolin");
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

