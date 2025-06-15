import { useState } from 'react';
import { motion } from 'framer-motion';

export default function Offer() {
    const plans = [
        {
            id: 'basic',
            icon: '🧰',
            title: 'Plan Podstawowy',
            desc: 'Podstawowe funkcje magazynowe, dodawanie części, przeglądanie listy i stany magazynowe.',
        },
        {
            id: 'pro',
            icon: '📊',
            title: 'Plan Pro',
            desc: 'Zaawansowane raportowanie, integracje z systemami zewnętrznymi, alerty o niskim stanie.',
        },
        {
            id: 'enterprise',
            icon: '🏢',
            title: 'Plan Enterprise',
            desc: 'Dedykowane wsparcie, możliwość rozszerzeń, zarządzanie wieloma magazynami i użytkownikami.',
        },
    ];

    const [selected, setSelected] = useState('pro');

    return (
        <motion.div
            className="max-w-5xl mx-auto px-6 py-16 bg-gray-50 dark:bg-gray-900 text-gray-900 dark:text-gray-100"
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
                Nasza oferta
            </motion.h1>

            <motion.p
                className="text-lg mb-12 text-center text-gray-700 dark:text-gray-300"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.4 }}
            >
                Oferujemy kompleksowe rozwiązania do zarządzania magazynem części samochodowych.
                Dostosowane do małych warsztatów i dużych firm logistycznych.
            </motion.p>

            <motion.div
                className="grid md:grid-cols-3 gap-8"
                initial={{ opacity: 0 }}
                animate={{ opacity: 1 }}
                transition={{ delay: 0.6 }}
            >
                {plans.map((plan) => (
                    <motion.div
                        key={plan.id}
                        onClick={() => setSelected(plan.id)}
                        className={`cursor-pointer bg-white dark:bg-gray-800 p-6 rounded-lg shadow-md hover:shadow-xl transition-all transform text-center ${
                            selected === plan.id ? 'border-2 border-blue-600 scale-105' : 'border border-gray-200 dark:border-gray-600'
                        }`}
                        whileHover={{ scale: 1.05 }}
                    >
                        <div className="text-4xl mb-4">{plan.icon}</div>
                        <h2 className="text-xl font-semibold text-blue-600 mb-2">{plan.title}</h2>
                        <p className="text-gray-600 dark:text-gray-300 text-sm mb-4">{plan.desc}</p>
                        <button
                            className={`px-4 py-2 rounded shadow ${
                                selected === plan.id
                                    ? 'bg-blue-600 text-white'
                                    : 'bg-gray-200 dark:bg-gray-700 text-gray-700 dark:text-gray-100 hover:bg-gray-300 dark:hover:bg-gray-600'
                            }`}
                        >
                            {selected === plan.id ? 'Wybrano' : 'Wybierz'}
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
                <p className="text-gray-700 dark:text-gray-300 mb-4">Potrzebujesz indywidualnej oferty?</p>
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
