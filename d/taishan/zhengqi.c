// Room: /d/taishan/zhengqi.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�����Ƿ���̨�ұߵ��������������˷���ʹ��ƽʱ����ɽʱ��
ͨ�����������ﴦ�����ֹ������������з��Űѻ�Ƥ�Σ�����ʹ��
���������濪���������Ҹ������ż�λ������ʿ������ȥɱ����
�ڣ�������Ȼ�������⡣
LONG
    );
    set("exits", ([
        "east" : __DIR__"fengchan",
    ]));
    set("objects",([
        __DIR__"npc/fa-e" : 1,
        __DIR__"npc/wei-shi2" : 2,
    ]));
        set("no_clean_up", 1);
    setup();
}

void update_here()
{
	remove_call_out("reset");
	call_out("reset", 1);
}
