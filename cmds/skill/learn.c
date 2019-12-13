// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

nosave string *valid_learn_skill = ({
	"yijing-force", "taixuan-gong","xixing-dafa",
	});

nosave mapping valid_learn_type = get_mapping_config(DATA_CONFIG_DIR+"mapping/skill.mapp");

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	mapping skl;
	string skill, teacher, skill_name, *sname;
	int times, i, is_couple, flag;
	object ob,home;	
	int master_skill, my_skill, gin_cost;
	
	reset_eval_cost();

	if ( me->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( !arg || arg=="?" || arg=="/?" )
		return notify_fail("ָ���ʽ��learn <����> at <����> from <ĳ��>\n");

	if ( sscanf(arg, "%s at %d from %s", skill, times, teacher) != 3 )
	if ( sscanf(arg, "%s %s %d", teacher, skill, times) != 3 )
		return notify_fail("ָ���ʽ��learn <����> at <����> from <ĳ��>\n");

	if ( times > 999 ) //ԭ��99
		return notify_fail("һ��ѧ��ô��,С���۵���Ŷ~\n");

	if ( (int) times < 1 )
		me->set("learn_cuowu",1);

	if ( (int) times < 1 )
		return notify_fail("��Ҫѧ���Σ�\n");

	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");

	if (me->query("learned_points",1))
		return notify_fail("��������,������������ʦ!\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("��Ҫ��˭��̣�\n");

	if( ob == me )
		return notify_fail("��....�������һ���Լ�������˵��\n");

	if( skill == "taixuan-gong" )
		return notify_fail("�������ֻ������\n");

	if( skill == "spells" )	
		return notify_fail("����ܲ��ܸ����ѧ��\n");

	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
	
	is_couple = 0;
	if( !me->is_apprentice_of(ob) )
	{
		if ( me->query("couple/couple_id") == ob->query("id") 
			&& ob->query("couple/couple_id") == me->query("id") )
			is_couple = 1;
	}

	if ( !is_couple && !(ob->recognize_apprentice(me)) )
	{
		return	notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
		//return notify_fail(HIY"����Ȼ��������ͽ�ܣ���Ҳ�������ʦ���������������ʦ�š�\n���ǼȲ���ͬһ���ɣ�����Ҳ�������������˽�½����似�أ�\n");
	}

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("���������±����ұ���ѧ�ˡ�\n");

	if (ob->is_fighting())
		return notify_fail("ʦ��æ��������ˣ�û������Ү��\n");

	if( ob->query("startroom") )
	{
		if( !home = find_object(ob->query("startroom")) )
			home = load_object(ob->query("startroom"));

		if ( !userp(ob) && environment(ob) != home )
		{	
			message_vision(CYN"$N˵������������æ���أ����һ�ȥ��˵�ɣ�\n"NOR,ob);	
			return 1;
		}
	}

	my_skill = me->query_skill(skill, 1);
	
	// ����ʦ��¼��
	if ( ob->prevent_learn(me,my_skill) )
		return notify_fail(ob->name() + "��Ը���������ܡ�\n");
     //�����װ���ܿ��Ա��������ѧϰ��bug
	if( my_skill >= (master_skill- ob->query_temp("suit_skill/"+skill)) )
		return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

	if( !SKILL_D(skill)->valid_learn(me) )
		return SKILL_D(skill)->valid_learn(me);
	// ���⼼�ܽ�ֹ�����ѧϰ
	if ( (string)SKILL_D(skill)->type() == "only_from_npc" && playerp(ob) )
		return notify_fail("����ܲ��ܺ����ѧ��\n");
	// lisa 2003.7.3
	if ( SKILL_D(skill)->valid_learn_ob(ob) )
	{
		if ( playerp(ob) ) return notify_fail("����ܲ��ܺ����ѧ��\n");
		if ( me->query("gender") == "����" 
			&& my_skill > 49 
			&& skill!="kuihua-xinfa" 
			&& skill!="yijing-force" ) 
			return notify_fail("���޸����ԣ����������������������"+to_chinese(skill)+"��\n");
		
		if ( member_array(skill, valid_learn_skill) == -1 )
		{
			flag = valid_learn_type[skill];
			skl = me->query_skills();
			sname  = keys(skl);
			for ( i=0; i<sizeof(sname); i++ )
			{
				if ( !SKILL_D(sname[i])->valid_learn_ob(ob) ) continue; // �����ڹ�
				if ( sname[i] == skill ) continue; // �Լ�����
				if ( member_array(sname[i], valid_learn_skill) != -1 ) continue; // ������ݵ��ڹ�
				if ( flag && valid_learn_type[sname[i]] == flag ) continue; // һЩ��������
				return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ"+to_chinese(skill)+"��\n"NOR);
			}
		}
	}

	gin_cost = (100 + my_skill * 2) / (int) me->query_int();

	if ( gin_cost < 1 )
		gin_cost = 1;
	
	if( !my_skill )
	{
		gin_cost *= 2;
		me->set_skill(skill,0);
	}
	
	if( (int)times > (int)me->query("potential") )
	{
		if ( me->query("potential") < 1 )
			return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
		else
			return notify_fail("���Ǳ�ܲ���ѧϰ��ô����ˡ�\n");
	}
	
	if ( me->query("jing") < 1 )
		return notify_fail("���Ѿ�̫���ˣ�û�а취�ټ���ѧϰ��\n");

	printf("����%s����йء�%s�������ʡ�\n", ob->name(), to_chinese(skill));
	
	if( ob->query("env/no_teach") )
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");
	
	tell_object(ob, sprintf("%s��������йء�%s�������⡣\n", me->name(), to_chinese(skill)));
	
	if( (int)ob->query("jing") > gin_cost * times / 5 )
	{
		if( userp(ob) )
			ob->receive_damage("jing", gin_cost * times / 5 + 1);
		else
			ob->receive_damage("jing", gin_cost * times / 10 + 1);
	}
	else
	{
		write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
		tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
		return 1;
	}

	if( (int)me->query("jing") >= times * gin_cost )
	{
		if( (string)SKILL_D(skill)->type() == "martial" 
		&& (my_skill+1) * (my_skill+1) / 10 * to_float(my_skill+1) 
			>= me->get_levelup_exp()/2*(me->query("xyzx_sys/level")+1) )
		{  	
			printf("��ĵȼ����㣬��%s�Ļش������޷���ᡣ\n", ob->name() );
		}
		else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				printf("������%s��ָ�����ԡ�%s����һ���ƺ���Щ�ĵá�\n", ob->name(), skill_name);
			else
				printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());

			for ( i = 0; i < times; i++ )
			{
				if(me->query_skill(skill,1)>= (master_skill - ob->query_temp("suit_skill/"+skill)))
                    break; //�����װ���ܿ��Ա��������ѧϰ��bug
				if( !SKILL_D(skill)->valid_learn(me) )
					break; //������书������������������ѧϰ���ܵȼ���ʱ����Ȼ�������ѧϰ��bug
				me->improve_skill(skill, 5 * (10 + random((int)me->query_int() - 9)));
			}

			me->add("potential", -(int)times);
			me->receive_damage("jing", times * gin_cost);
		}
	}
	else
	{
		gin_cost = me->query("jing");
		me->receive_damage("jing", gin_cost);
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : learn <����> at <����> from <ĳ��>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����
����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�
�������ָ�� : teach, apprentice, practice, skills, study
HELP
        );
        return 1;
}
