// Room: /d/emei/duguangtai.c ������ �ù�̨
// create by host dec,20 1997
inherit ROOM;


void create()
{
	set("short", "�ù�̨");
	set("long", @LONG
����һ�����Ĺ㳡����������Կ������ҵ�ȫò��ÿ�յ���ϼ������
���վ�ڶù�̨�ϣ�������󽫻ó�һ�ֹ⻷����ɫ������ʡ��ڹ㳡��
�������ż��ӣ���������˱������ڹ㳡����һЩ���ҵ��������������
ϰ�书�����໥�ֽ̡�
LONG
	);

          set("outdoors", "emei");
	set("exits", ([
               "northdown" : __DIR__"jinding",
               "east":__DIR__"huazangan",
	]));
        set("objects",([
                 CLASS_D("emei") + "/jingxu": 1,
          "/d/shaolin/npc/mu-ren" : 2,
	]));
	setup();

}

