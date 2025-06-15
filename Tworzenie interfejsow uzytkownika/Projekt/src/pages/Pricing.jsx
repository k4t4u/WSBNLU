import { useState } from 'react';
import { motion } from 'framer-motion';

export default function Pricing() {
    const [selected, setSelected] = useState('Plan Pro');

    const plans = [
        {
            title: 'Plan Start',
            price: '0 zł',
            newFeatures: ['Dodawanie części', 'Podstawowe wyszukiwanie', '1 magazyn'],
            inherits: null,
        },
        {
            title: 'Plan Pro',
            price: '49 zł / miesiąc',
            newFeatures: ['Zaawansowane filtry', 'Raporty i alerty', 'Do 5 magazynów'],
            inherits: 'Plan Start',
        },
        {
            title: 'Plan Biznes',
            price: '99 zł / miesiąc',
            newFeatures: ['Integracje API', 'Zarządzanie użytkownikami', 'Nieograniczona liczba magazynów'],
            inherits: 'Plan Pro',
        },
    ];

    return (
        <motion.div
            className="max-w-6xl mx-auto px-6 py-16 bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100"
            initial={{ opacity: 0, y: 10 }}
            animate={{ opacity: 1, y: 0 }}
            exit={{ opacity: 0, y: -10 }}
            transition={{ duration: 0.4 }}
        >
            <motion.h1
                className="text-4xl font-bold mb-8 text-center"
                initial={{ opacity: 0, y: 20 }}
                animate={{ opacity: 1, y: 0 }}
                transition={{ delay: 0.2 }}
            >
                Cennik
            </motion.h1>

            <motion.p
                className="text-lg mb-12 text-center max-w-2xl mx-auto text-gray-700 dark:text-gray-300"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.4 }}
            >
                Wybierz plan, który najlepiej odpowiada Twoim potrzebom. Każdy kolejny plan zawiera wszystkie funkcje poprzedniego oraz dodatkowe rozszerzenia.
            </motion.p>

            <motion.div
                className="grid md:grid-cols-3 gap-8"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.6 }}
            >
                {plans.map((plan) => (
                    <motion.div
                        key={plan.title}
                        onClick={() => setSelected(plan.title)}
                        className={`rounded-lg shadow-md p-6 bg-white dark:bg-gray-800 cursor-pointer transition-all border-2 flex flex-col items-center ${
                            selected === plan.title
                                ? 'border-blue-600 scale-105'
                                : 'border-transparent hover:border-blue-400 dark:hover:border-blue-500'
                        }`}
                        whileHover={{ scale: 1.05 }}
                    >
                        <h2 className="text-xl font-semibold mb-1">{plan.title}</h2>

                        <p className="text-sm italic mb-2 text-gray-500 dark:text-gray-400">
                            {plan.inherits
                                ? <>Zawiera wszystko z <strong>{plan.inherits}</strong>, plus:</>
                                : 'Podstawowy plan'}
                        </p>

                        <p className="text-3xl font-bold text-blue-600 mb-6">{plan.price}</p>

                        <ul className="space-y-2 text-sm mb-6 w-full">
                            {plan.newFeatures.map((feature, i) => (
                                <li key={i} className="text-gray-600 dark:text-gray-300 flex items-center gap-2">
                                    ➕ {feature}
                                </li>
                            ))}
                        </ul>

                        <button
                            className={`mt-auto px-6 py-2 rounded w-full transition text-white ${
                                selected === plan.title
                                    ? 'bg-blue-700'
                                    : 'bg-blue-600 hover:bg-blue-700'
                            }`}
                        >
                            {selected === plan.title ? 'Wybrano ten plan' : 'Wybierz plan'}
                        </button>
                    </motion.div>
                ))}
            </motion.div>

            <motion.div
                className="text-center mt-12"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.8 }}
            >
                <p className="text-gray-700 dark:text-gray-300 mb-4">Masz pytania lub potrzebujesz indywidualnej wyceny?</p>
                <a
                    href="/contact"
                    className="inline-block bg-indigo-600 hover:bg-indigo-700 text-white px-6 py-3 rounded-lg transition"
                >
                    Skontaktuj się z nami
                </a>
            </motion.div>
        </motion.div>
    );
}
