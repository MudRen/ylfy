// Room: /d/emei/guanyintang.c ������ ������
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "������");
	set("long", @LONG
����һ���������������۵ķ��ã�����ȫ��������ʯ�����ɡ���������
��Ȼ�ȷ���һ����ǧ�ֹ����������ȸ������Ĵ��ϡ����������������
���֣�ÿֻ���������ϸ�ᣬ���÷�����ǧ�˰�̬��һ��ͬ�������ҽ�ͯ��
��Ů�������ԡ�
LONG
	);

	set("exits", ([
                "northwest" :  __DIR__"huayanding",
                "east" : __DIR__"xixiangchi",
	]));

	set("objects",([
             CLASS_D("emei") + "/jingkong": 1,
	]));

	setup();
}
