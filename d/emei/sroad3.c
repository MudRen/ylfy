// Room: /d/emei/sroad3.c  

inherit ROOM;

void create()
{
	set("short", "��Դ����");
	set("long", @LONG
������һ��ͨ�������ĵ���ʯ·�ϣ���·���Էֲ�����෿�ݣ�����һ
Ƭ�ž���ż�������ļ���Ȯ�ͣ��Եİ�����͡���ÿ����������ȴ��������
��Ϧ��������£���ũ�Ĵ����Ǿ��������һʱ��ƽ����С��������˱���
�ļž�����������֡�
LONG
	);

        set("exits", ([
              "south":__DIR__"sroad2",
              "north":__DIR__"center",
	]));
        set("outdoors", "emei");
	setup();
}
