// Room: /d/emei/lingwenge.c ������ ���ĸ�


inherit ROOM;


void create()
{
	 set("short","���ĸ�");
      set("long",@LONG
�����Ǹ����ֵ����ĸ������־���ʦ̫���ڷ𷨵ĵط�����������С��
�������ԣ��ƺ�������ʦ̫�Ľ̻ޡ����ڲ��ü�ª����ǽ���ż������Σ�����
���ż������š�������һ������������һ��ի����
LONG);

	set("exits", ([
               "west":__DIR__"fushouan",
		
	]));

	set("objects",([
		"d/emei/npc/girldizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
