// Room: /d/emei/baoguosi.c ������ ������


inherit ROOM;


void create()
{
        set("short", "���");
	set("long", @LONG
���ﱨ���µ���������˽Ƕ���������ʮ����ͭ�壬΢�紵������ͣ
�������ö�����������ľ��Ϊ����������ȯ�������й�����һ������ľ���
�ġ�ǧ��ǧ�۹���������������ǧ�֣�ÿ��һ�ۣ���˼����񹤾�����
LONG
	);
        set("valid_startroom", 1);
	set("exits", ([
                "north":__DIR__"baoguosi",
	]));
        set("objects",([
               CLASS_D("emei") + "/jingxin" : 1,
	]));

	setup();
}
