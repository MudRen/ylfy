// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
    set("short", "����̨");
    set("long", @LONG
�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ�
�������������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨��
�ڷ��ź����������������ڴ��������¡�̨�ϸ߸�����һ���죬
���飺�����е� �ĸ����֡� �������Ҹ���������λ������ʿ����
�߶�����һ���Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ�������
LONG
    );
        set("valid_startroom", 1);
    set("exits", ([
		"up" : __DIR__"fengchan",
        "down" : __DIR__"yuhuang",
        "east" : __DIR__"xiayi-new",
        "west" : __DIR__"zhengqi-new",
    ]));
    set("objects",([
                "/d/taishan/npc/meng-zhu-new" : 1,
        __DIR__"npc/wei-shi1" : 2,
    ]));
        set("no_clean_up", 1);
    set("outdoors", "taishan");
    setup();
}

void update_here()
{
	remove_call_out("reset");
	call_out("reset", 1);
}