// Room: /d/taishan/xiayi.c
// Date: CSWORD 96/03/25
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�����Ƿ���̨��ߵ�������������������ʹ��ƽʱ����ɽʱ��
ͨ������������������ֹ������������з��Ű�̫ʦ�Σ�����ʹ��
���������濪���������Ҹ������ż�λ������ʿ������ȥ������
�ݣ�����һ��ׯ������
LONG
    );
    set("exits", ([
        "west" : __DIR__"fengchan-new",
    ]));
    set("objects",([
                "/d/taishan/npc/shang-shan-new" : 1,
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
