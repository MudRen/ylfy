// Room: /d/shaolin/fanting.c
// Date: YZC 96/01/19
inherit ROOM;
string* names = ({
    __DIR__"obj/mala-doufu",
    __DIR__"obj/bocai-fentiao",
    __DIR__"obj/shanhu-baicai",
    __DIR__"obj/liuli-qiezi",
});
void create()
{
    set("short", "ի��");
    set("long", @LONG
�����������ȫ����ɮ��ի�ĵط���ի���������������
ǧ��ͬʱ���͡��Ӷ�����һ���Ű����˳����Ĳ����ͳ��ʣ���λ
С����������æµ�Ų�����ի�����ϰ��˼��趹�������������
�Լ���Ѽ����ζ��ʳ��
LONG
    );
    set("exits", ([
        "east" : __DIR__"guangchang3",
        "north" : __DIR__"fanting1",
    ]));
    set("objects",([
        __DIR__"npc/shaofan-seng" : 1,
        __DIR__"obj/qingshui-hulu" : 1,
        names[random(sizeof(names))]: 1,
        names[random(sizeof(names))]: 1,        
    ]));
    setup();
}
int valid_leave(object me, string dir)
{
    if ( present("shaofan seng", environment(me)) )
    if (    present("mala doufu", me) || 
            present("bocai fentiao", me) || 
            present("shanhu baicai", me) || 
            present("liuli qiezi", me) || 
            present("qingshui hulu", me))  
    {
        if ((dir == "east") || (dir == "north"))
        {
            return notify_fail("�����ӷ����ʳ�������ˣ�������ɮ�˳�ʲô !\n");
        }
    }
    return ::valid_leave(me, dir);
}
