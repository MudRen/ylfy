// location.c

#include <ansi.h>
inherit F_CLEAN_UP;

string *place_desc = ({
	"�͵�",
	"����",
	"���Ĺ㳡",
	"��ʯ���",
	"ɽ·",
	"�����"
	});

int main(object me, string arg)
{
	object ob,where;
	int sp, dp;
	int lvl, busy_time;
	int b1,b2;
	
	seteuid(getuid());
	
	if( (lvl = (int)me->query_skill("count", 1)) < 900 )
		return notify_fail("�������������δ���죬�޷��˽���˵����ڣ�\n");
	
	if (!environment(me))
		return notify_fail("��ҪӰ����ˣ�������һ����ĵط��ɡ�\n");
	
	if (environment(me)->query("sleep_room"))
		return notify_fail("��ҪӰ����ˣ�������һ����ĵط��ɡ�\n");
	
	if( environment(me)->query("no_beg") && environment(me)->query("no_fight") && environment(me)->query("no_steal"))
		return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);
	
	if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked"))
		return notify_fail("��������æ���ء�\n");
	
	if ( !arg )
		return notify_fail("��Ҫ����˭�����ڣ�\n");
	
	if ( present(arg, environment(me)) )
		return notify_fail("��Ҫ�������˾��ڱ��ϣ���������ɣ�\n");
	
	ob = find_player(arg);
	
	if (!ob)
		ob = find_living(arg);
	
	if (!ob)
		return notify_fail("��Ҫ����˭�����ڣ�\n");
	
	if( !wizardp(me) && wizardp(ob) )
		return notify_fail("��Ҫ����˭�����ڣ�\n");
	
	if ( ob == me )
		return notify_fail("��û���᱿�ɣ�Ҫ���˸������Լ������ڣ�\n");
	
	if ( me->query("jing") <= 60 )
		return notify_fail("������̫���ˣ��޷�ȥ�������˵����ڡ�\n");
	
	if ( me->query("qi") <= 60 )
		return notify_fail("������̫���ˣ��޷�ȥ�������˵����ڡ�\n");
	
	message_vision(CYN"$N����һֻ����������������Ĵָ�����������������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢��\n������λ��ϸ��������������\n\n\n"NOR, me);
	
	busy_time = (int)(30 - lvl/100);
	
	if(busy_time < 5)
		busy_time = 5;
	
	if(busy_time > 30)
		busy_time = 30;
	
	me->start_busy(busy_time);
	me->add("jing", -me->query("max_jing")/15);
	me->add("qi", -me->query("max_qi")/15);
	
	message_vision(HIG"ֻ��$N��ϥ���£�˫�����գ����������дʣ���Ȼ��¶΢Ц: ����!\n\n"NOR,me);
	
	sp = me->query_skill("count",1)*10 + me->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	
	if ( random(sp) < random(dp)/2 )
	{
		write(HIR"���龫���������˰��Σ�ȴ����һ�����á��� \n"NOR);
		me->set("jing", 20);
		me->improve_skill("count",random((int)me->query_int()));
		return notify_fail( HIY"������Ȼ���£�ҡ��ҡͷ��˵�������Եģ�\n"NOR);
	}
	
	where = environment(ob);
	
	if (!where)
		return notify_fail("����˲�֪��������Ү...\n");
	
	if( !(where = environment(ob)) )
		return notify_fail("����˲�֪��������Ү...\n");
	
	if( !wizardp(me) && wizardp(ob) )
	{
		if ( ob->query("env/invisibility") == 10 )
			return notify_fail("����˲�֪��������Ү...\n");
		return notify_fail("�󵨣�����ı����ʦ��\n");
	}
	
	if ( random(sp) > random(dp) )
	{
		if (strsrch(file_name(where), "changan") >= 0)
			tell_object(me,    ob->name()+"�����ڳ����ǣ�\n"NOR);
		
		if (strsrch(file_name(where), "shashou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����ɱ��¥��\n");
		
		if (strsrch(file_name(where), "honghua") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں컨�ᣡ\n");
		
		if (strsrch(file_name(where), "tangmen") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ţ�\n");
		
		if (strsrch(file_name(where), "city") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݳǣ�\n");
		
		if (strsrch(file_name(where), "yihua") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����ƻ�����\n");
		
		if (strsrch(file_name(where), "nanyang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����������\n");
		
		if (strsrch(file_name(where), "new") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������������\n");
		
		if (strsrch(file_name(where), "city3") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڳɶ��ǣ�\n");
		
		if (strsrch(file_name(where), "city2") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ����ǣ�\n");
		
		if (strsrch(file_name(where), "dali") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڴ���ǣ�\n");
		
		if (strsrch(file_name(where), "death") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڵ����\n");
		
		if (strsrch(file_name(where), "emei") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڶ�üɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "foshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڷ�ɽ��\n");
		
		if (strsrch(file_name(where), "fuzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڸ��ݳǣ�\n");
		
		if (strsrch(file_name(where), "gaibang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����ؤ���\n");
		
		if (strsrch(file_name(where), "guanwai") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڹ��⣡\n");
		
		if (strsrch(file_name(where), "hangzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں��ݳǣ�\n");
		
		if (strsrch(file_name(where), "hengshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "henshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "huanggon") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻʹ������\n");
		
		if (strsrch(file_name(where), "lingjiu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������շ��ϣ�\n");
		
		if (strsrch(file_name(where), "mingjiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ��������ɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "qingcheng") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "quanzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����Ȫ�ݳǣ�\n");
		
		if (strsrch(file_name(where), "shaolin") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����������\n");
		
		if (strsrch(file_name(where), "shenlong") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����������ϣ�\n");
		
		if (strsrch(file_name(where), "songshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������ɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "suzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݳǣ�\n");
		
		if (strsrch(file_name(where), "taishan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����̩ɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "taohua") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����һ�����\n");
		
		if (strsrch(file_name(where), "tianlongsi") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����������\n");
		
		if (strsrch(file_name(where), "wudang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����䵱ɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "xiakedao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������͵��ϣ�\n");
		
		if (strsrch(file_name(where), "xiaoyao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������ң���\n");
		
		if (strsrch(file_name(where), "xingxiu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������޺���\n");
		
		if ((strsrch(file_name(where), "xuedao") >= 0) ||
		   (strsrch(file_name(where), "xueshan") >= 0))
			tell_object(me,    ob->name()+"�Ĵ��λ���ڴ�ѩɽ�ϣ�\n");
		
		if (strsrch(file_name(where), "mr") >= 0)	
			tell_object(me,    ob->name()+"�Ĵ��λ���������룡\n");
		
		if (strsrch(file_name(where), "gumu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ��������ɽ��\n");
		
		if (strsrch(file_name(where), "meizhuang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����÷ׯ��\n");
		
		if (strsrch(file_name(where), "hg") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻʹ����ڣ�\n");
		
		if (strsrch(file_name(where), "nio") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����ţ�Ҵ壡\n");			
		
		if (strsrch(file_name(where), "feihu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڴ������أ�\n");
		
		if (strsrch(file_name(where), "wuguan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����������ݣ�\n");
		
		if (strsrch(file_name(where), "village") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻ�ɽ�壡\n");
		
		if (strsrch(file_name(where), "wanjiegu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������ٹȣ�\n");
		
		if (strsrch(file_name(where), "pingan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����ƽ���ǣ�\n");
		
		if (strsrch(file_name(where), "taohuacun") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����һ��壡\n");
		
		if (strsrch(file_name(where), "lingxiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���������ǣ�\n");
		
		if (strsrch(file_name(where), "wudujiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����嶾�̣�\n");
		
		if (strsrch(file_name(where), "jqg") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ھ���ȣ�\n");
		
		if (strsrch(file_name(where), "sdxl") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڽ�ħ�������Ĺ��\n");
		
		if (strsrch(file_name(where), "fairyland") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ظ����ĺ�÷ɽׯ��\n");
		
		if (strsrch(file_name(where), "changcheng") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ����Ա����ǣ�\n");
		
		if (strsrch(file_name(where), "jyguan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���������Ա������أ�\n");
		
		if (strsrch(file_name(where), "lanzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݣ�\n");
		
		if (strsrch(file_name(where), "yanjing") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����ྩ��\n");
		
		if (strsrch(file_name(where), "jingzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ھ��ݣ�\n");
		
		if (strsrch(file_name(where), "kunming") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����������\n");
		
		if (strsrch(file_name(where), "ruzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݳǣ�\n");
		
		if (strsrch(file_name(where), "lingshedao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ߵ���\n");
		
		if (strsrch(file_name(where), "qianjin") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ���ǧ��¥��\n");
		
		if (strsrch(file_name(where), "menggu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����ɹŲ�ԭ��\n");
		
		if (strsrch(file_name(where), "yinju") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����һ�ƴ�ʦ�ӣ�\n");
		
		if (strsrch(file_name(where), "huizhu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻ��岿�䣡\n");
		
		if (strsrch(file_name(where), "tiezhang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���������ţ�\n");
		
		if (strsrch(file_name(where), "kunlun") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ��������ɽ��\n");
		
		if (strsrch(file_name(where), "baituo") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڰ���ɽ��\n");
		
		if (strsrch(file_name(where), "binghuodao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ��𵺣�\n");
		
		if (strsrch(file_name(where), "gaochang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڸ߲��Թ���\n");
		
		if (strsrch(file_name(where), "gumu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڹ�Ĺ�ɣ�\n");
		
		if (strsrch(file_name(where), "heimuya") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ľ�£�\n");
		
		if (strsrch(file_name(where), "huanghe") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻƺӾ�����\n");
		
		if (strsrch(file_name(where), "huanhua") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����佻���\n");	
		
		if (strsrch(file_name(where), "lingzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݣ�\n");
		
		if (strsrch(file_name(where), "meizhuang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����÷ׯ��\n");
		
		if (strsrch(file_name(where), "mingjiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������̣�\n");
	}
	
	if (random(10)>7)
	{
		if (userp(ob))
		{
			if( (random(lvl/4)) < ob->query("kar") )
				tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......\n"NOR);
		}
		
		b1=random(30)+10;
		
		b2=random(20)+7;
		
		printf("%s������%s��\n",(string)ob->name(), place_desc[random(sizeof(place_desc))]);
		return 1;
	}
	
	if (userp(ob))
	{
		if( (random(lvl/4)) < ob->query("kar") )
			tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......\n"NOR);
	}
	
	b1=random(30)+10;
	b2=random(20)+7;
	
	printf("%s������%s��\n",(string)ob->name(),(string)where->query("short"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: location <��ҵ� ID>

���ָ���������֪���Ŀǰ���ڵ�λ��.	

HELP
	);
	return 1;
}

