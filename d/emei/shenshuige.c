// Room: /d/emei/shenshuige.c ��ˮ��


inherit ROOM;


void create()
{
        set("short", "��Һ��");
	set("long", @LONG
���������ˮ�������Һ�أ��˳���Ȼ���󣬵�������Ȫˮ���������ҳ�ˮ
��ɢ����΢΢����������˵��ƽ���˺����������ˮ��ʹ���������٣��������
�˺��˿���������������Ϊ���ʴ˶���ר�����˿��ܴ˳أ�����Ҳ�Ƕ���ɮ��ȡ
ˮ�ĵط���
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "southup" : __DIR__"qingyinge",
                "northdown":__DIR__"lshenggang",
                "east": __DIR__"zfengsi",
	]));


	set("objects",([
                __DIR__"npc/zhaolingzhu": 1,
	]));

	setup();
}
